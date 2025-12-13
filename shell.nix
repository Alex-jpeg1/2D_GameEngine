{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    gcc
    cmake
    pkg-config
    
    glfw
    glew
    xorg.libX11      
    xorg.libXi       
    xorg.libXrandr   
    xorg.libXext     
    xorg.libXcursor  
    xorg.libXinerama
  ];
  shellHook = ''
    echo "Mediul de dezvoltare OpenGL/C++ a fost incarcat."
  '';
}