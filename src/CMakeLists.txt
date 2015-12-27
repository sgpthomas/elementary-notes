#define app source files
set (APP_SOURCES
    Keep.vala
    Config.vala
)

#define app source files : core
set (APP_SOURCES ${APP_SOURCES}
    Core/Database.vala
    Core/DatabaseManager.vala
    Core/Note.vala
    Core/NoteManager.vala
)

#define app source files : services
set (APP_SOURCES ${APP_SOURCES}
    Services/StyleManager.vala
)

#define app source files : widgets
set (APP_SOURCES ${APP_SOURCES}
    Widgets/Editor.vala
    Widgets/EditorView.vala
    Widgets/FormatPopover.vala
    Widgets/KeepHeaderBar.vala
    Widgets/Sidebar.vala
    Widgets/Toolbar.vala
)

#define app source files : window
set (APP_SOURCES ${APP_SOURCES}
    Window/HeaderBarWindow.vala
    #Window/MainWindow.vala
)

#compiling sources
vala_precompile (VALA_C ${EXEC_NAME}
    ${APP_SOURCES}

#packages to compile with model
PACKAGES
    ${SOURCE_DEPS}
#OPTIONS
    #${VALAC_OPTIONS}
)

#automatically generate .pot template files
set (_pot_file ${CMAKE_SOURCE_DIR}/po/${PROJECT_NAME}.pot)
add_custom_command (OUTPUT ${_pot_file}
    COMMAND xgettext --output=${_pot_file} ${APP_SOURCES}
    DEPENDS ${APP_SOURCES}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Extract translatable messages to ${_pot_file}")
add_custom_target (pot_file ALL DEPENDS ${_pot_file})

#make executable
add_executable (${EXEC_NAME} ${VALA_C})

#install binaries
install (TARGETS ${EXEC_NAME} RUNTIME DESTINATION bin)
