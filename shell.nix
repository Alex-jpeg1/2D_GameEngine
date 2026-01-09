{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    gcc
    cmake
    pkg-config

    python311Packages.glad 
    glfw
    glew
    glm 
    
    xorg.libX11      
    xorg.libXi       
    xorg.libXrandr   
    xorg.libXext     
    xorg.libXcursor  
    xorg.libXinerama
    libGL
  ];
  LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath (with pkgs; [
    libGL
    glfw
    xorg.libX11
  ]);

  shellHook = ''
    echo "Mediul de dezvoltare OpenGL/C++ a fost incarcat."
    echo "   glad --generator=c --spec=gl --profile=core --out-path=./glad"
  '';
}