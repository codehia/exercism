//
// This is only a SKELETON file for the 'Protein Translation' exercise. It's been provided as a
// convenience to get you started writing code faster.
//
const PROTEINS = {'AUG':'Methionine',
                  'UUU':'Phenylalanine',
                  'UUC':'Phenylalanine',
                  'UUA':'Leucine',
                  'UUG':'Leucine',
                  'UCU': 'Serine',
                  'UCC' : 'Serine',
                  'UCA' : 'Serine',
                  'UCG': 'Serine',
                  'UAU': 'Tyrosine',
                  'UAC': 'Tyrosine',
                  'UGU': 'Cysteine',
                  'UGC': 'Cysteine',
                  'UGG':	'Tryptophan',
                  'UAA': 'STOP',
                  'UAG': 'STOP',
                  'UGA': 'STOP'	}
export const translate = (rna) => {
  if(!rna)
    return [];

  let proteinArr = [];
  for (var i = 0; i < rna.length; i += 3) {
    switch (PROTEINS[rna.substring(i, i +3)]) {
      case 'STOP':
        return proteinArr;
        break;
      case undefined:
        throw new Error('Invalid codon');
        break;
      default:
        proteinArr.push(PROTEINS[rna.substring(i, i +3)])
    }
}
  return proteinArr;
};
