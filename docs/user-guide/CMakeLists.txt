SET(USERGUIDESRC ${CMAKE_CURRENT_SOURCE_DIR})
SET(USERGUIDE ${CMAKE_BINARY_DIR}/docs/user-guide)

FILE(MAKE_DIRECTORY ${USERGUIDE}/html)

FIND_PROGRAM(HTLATEX htlatex)
MARK_AS_ADVANCED(HTLATEX)
ADD_CUSTOM_TARGET(user-guide-html
    export TEXINPUTS=${USERGUIDESRC}//: && ${HTLATEX} ${USERGUIDESRC}/user-guide.tex 
    "${USERGUIDESRC}/styling.cfg,html,2,next,NoFonts"
    WORKING_DIRECTORY ${USERGUIDE}/html
)

FIND_PROGRAM(PDFLATEX pdflatex)
MARK_AS_ADVANCED(PDFLATEX)
FIND_PROGRAM(BIBTEX bibtex)
MARK_AS_ADVANCED(BIBTEX)
FIND_PROGRAM(MAKEINDEX makeindex)
MARK_AS_ADVANCED(MAKEINDEX)

ADD_CUSTOM_TARGET(user-guide-pdf
    ${PDFLATEX} --output-directory ${USERGUIDE} ${USERGUIDESRC}/user-guide.tex
    COMMAND TEXMFOUTPUT=${USERGUIDE} ${BIBTEX} ${USERGUIDE}/user-guide.aux
    COMMAND TEXMFOUTPUT=${USERGUIDE} ${MAKEINDEX} ${USERGUIDE}/user-guide.idx
    COMMAND ${PDFLATEX} --output-directory ${USERGUIDE}
        ${USERGUIDESRC}/user-guide.tex
    WORKING_DIRECTORY ${USERGUIDESRC}
)
