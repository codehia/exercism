//
// This is only a SKELETON file for the 'Resistor Color Duo' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const value = (colors) => {

  return(Number(String(COLORS.indexOf(colors[0])) + String(COLORS.indexOf(colors[1]))));
};

const COLORS = ["black","brown","red","orange","yellow","green","blue","violet","grey","white"];
