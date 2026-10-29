{ pkgs, ... }:

{
  packages = with pkgs; [
    git
    exercism
  ];
  languages.nix.enable = true;
}
