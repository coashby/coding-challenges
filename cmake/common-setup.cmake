
function(common_setup path_prefix)
    include("${path_prefix}/build-settings.cmake")
    include("${path_prefix}/compiler-warnings.cmake")
    include("${path_prefix}/cxx-language-standard.cmake")
endfunction()

function(project_intro_message project_name)
    message("*****************************************************************")
    message("Running CMake for ${project_name}...")
    message("*****************************************************************")
endfunction(project_intro_message)
