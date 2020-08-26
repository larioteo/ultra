﻿# Preparation
set (DESIGNER_HEADERS "")
set (DESIGNER_SOURCES "")

# Default
set(DESIGNER_DEFAULT_HEADERS )
set(DESIGNER_DEFAULT_SOURCES
	"Spectra.cpp"
)
list(APPEND DESIGNER_HEADERS ${DESIGNER_DEFAULT_HEADERS})
list(APPEND DESIGNER_SOURCES ${DESIGNER_DEFAULT_SOURCES})

# Menues
set(DESIGNER_MENU_HEADERS
	"Menu/Menues.h"
	"Menu/File.h"
	"Menu/Edit.h"
	"Menu/View.h"
	"Menu/Tools.h"
	"Menu/Help.h"
)
set(DESIGNER_MENU_SOURCES
)
list(APPEND DESIGNER_HEADERS ${DESIGNER_MENU_HEADERS})
list(APPEND DESIGNER_SOURCES ${DESIGNER_MENU_SOURCES})

# Menues
set(DESIGNER_VIEW_HEADERS
    "View/Browser.h"
	"View/Views.h"
	"View/Console.h"
	"View/Scene.h"
	"View/StyleEditor.h"
	"View/TextEditor.h"
)
set(DESIGNER_VIEW_SOURCES
    "View/Browser.cpp"
	"View/TextEditor.cpp"
)
list(APPEND DESIGNER_HEADERS ${DESIGNER_VIEW_HEADERS})
list(APPEND DESIGNER_SOURCES ${DESIGNER_VIEW_SOURCES})
