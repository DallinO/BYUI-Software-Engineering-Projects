'''****************************************************************************
This function stores the periodic table dictionary into a variable.
****************************************************************************'''
def make_periodic_table():
    periodic_table = {
    'Ac':	['Actinium', 227],
    'Ag':	['Silver', 107.8682],
    'Al':	['Aluminum', 26.9815386],
    'Am':	['Americium',	243],
    'Ar':	['Argon',	39.948],
    'As':	['Arsenic',	74.9216],
    'At':	['Astatine',	210],
    'Au':	['Gold',	196.966569],
    'B':	['Boron',	10.811],
    'Ba':	['Barium',	137.327],
    'Be':	['Beryllium',	9.012182],
    'Bh':	['Bohrium',	272],
    'Bi':	['Bismuth',	208.9804],
    'Bk':	['Berkelium',	247],
    'Br':	['Bromine',	79.904],
    'C':	['Carbon',	12.0107],
    'Ca':	['Calcium',	40.078],
    'Cd':	['Cadmium',	112.411],
    'Ce':	['Cerium',	140.116],
    'Cf':	['Californium',	251],
    'Cl':	['Chlorine',	35.453],
    'Cm':	['Curium',	247],
    'Cn':	['Copernicium',	285],
    'Co':	['Cobalt',	58.933195],
    'Cr':	['Chromium',	51.9961],
    'Cs':	['Cesium',	132.9054519],
    'Cu':	['Copper',	63.546],
    'Db':	['Dubnium',	268],
    'Ds':	['Darmstadtium',	281],
    'Dy':	['Dysprosium',	162.5],
    'Er':	['Erbium',	167.259],
    'Es':	['Einsteinium',	252],
    'Eu':	['Europium',	151.964],
    'F':	['Fluorine',	18.9984032],
    'Fe':	['Iron',	55.845],
    'Fl':	['Flerovium',	289],
    'Fm':	['Fermium',	257],
    'Fr':	['Francium',	223],
    'Ga':	['Gallium',	69.723],
    'Gd':	['Gadolinium',	157.25],
    'Ge':	['Germanium',	72.64],
    'H':	['Hydrogen',	1.00794],
    'He':	['Helium',	4.002602],
    'Hf':	['Hafnium',	178.49],
    'Hg':	['Mercury',	200.59],
    'Ho':	['Holmium',	164.93032],
    'Hs':	['Hassium',	270],
    'I':	['Iodine',	126.90447],
    'In':	['Indium',	114.818],
    'Ir':	['Iridium',	192.217],
    'K':	['Potassium',	39.0983],
    'Kr':	['Krypton',	83.798],
    'La':	['Lanthanum',	138.90547],
    'Li':	['Lithium',	6.941],
    'Lr':	['Lawrencium',	262],
    'Lu':	['Lutetium',	174.9668],
    'Lv':	['Livermorium',	293],
    'Mc':	['Moscovium',	288],
    'Md':	['Mendelevium',	258],
    'Mg':	['Magnesium',	24.305],
    'Mn':	['Manganese',	54.938045],
    'Mo':	['Molybdenum',	95.96],
    'Mt':	['Meitnerium',	276],
    'N':	['Nitrogen',	14.0067],
    'Na':	['Sodium',	22.98976928],
    'Nb':	['Niobium',	92.90638],
    'Nd':	['Neodymium',	144.242],
    'Ne':	['Neon',	20.1797],
    'Nh':	['Nihonium',	284],
    'Ni':	['Nickel',	58.6934],
    'No':	['Nobelium',	259],
    'Np':	['Neptunium',	237],
    'O':	['Oxygen',	15.9994],
    'Og':	['Oganesson',	294],
    'Os':	['Osmium',	190.23],
    'P':	['Phosphorus',	30.973762],
    'Pa':	['Protactinium',	231.03588],
    'Pb':	['Lead',	207.2],
    'Pd':	['Palladium',	106.42],
    'Pm':	['Promethium',	145],
    'Po':	['Polonium',	209],
    'Pr':	['Praseodymium',	140.90765],
    'Pt':	['Platinum',	195.084],
    'Pu':	['Plutonium',	244],
    'Ra':	['Radium',	226],
    'Rb':	['Rubidium',	85.4678],
    'Re':	['Rhenium',	186.207],
    'Rf':	['Rutherfordium',	267],
    'Rg':	['Roentgenium',	280],
    'Rh':	['Rhodium',	102.9055],
    'Rn':	['Radon',	222],
    'Ru':	['Ruthenium',	101.07],
    'S':	['Sulfur',	32.065],
    'Sb':	['Antimony',	121.76],
    'Sc':	['Scandium',	44.955912],
    'Se':	['Selenium',	78.96],
    'Sg':	['Seaborgium',	271],
    'Si':	['Silicon',	28.0855],
    'Sm':	['Samarium',	150.36],
    'Sn':	['Tin',	118.71],
    'Sr':	['Strontium',	87.62],
    'Ta':	['Tantalum',	180.94788],
    'Tb':	['Terbium',	158.92535],
    'Tc':	['Technetium',	98],
    'Te':	['Tellurium',	127.6],
    'Th':	['Thorium',	232.03806],
    'Ti':	['Titanium',	47.867],
    'Tl':	['Thallium',	204.3833],
    'Tm':	['Thulium',	168.93421],
    'Ts':	['Tennessine',	294],
    'U':	['Uranium',	238.02891],
    'V':	['Vanadium',	50.9415],
    'W':	['Tungsten',	183.84],
    'Xe':	['Xenon',	131.293],
    'Y':	['Yttrium',	88.90585],
    'Yb':	['Ytterbium',	173.054],
    'Zn':	['Zinc',	65.38],
    'Zr':	['Zirconium',	91.224],
    }

    return periodic_table

class FormulaError(ValueError):
    '''FormulaError is the type of error that
    parse_formula will raise if a formula is invalid.
    '''
    
    pass

'''****************************************************************************
This function reads the formula input and creates a complex list that stores
the number of each element in the molecule.
****************************************************************************'''
def parse_formula(formula, periodic_table):
    def parse_quant(formula, index):
        quant = 1
        if index < len(formula) and formula[index].isdecimal():
            start = index
            index += 1
            while index < len(formula) and formula[index].isdecimal():
                index += 1
            quant = int(formula[start:index])
        return quant, index

    def get_quant(elems, symbol):
        return 0 if symbol not in elems else elems[symbol]

    def parse_r(formula, index, level):
        start_index = index
        start_level = level
        elems = {}
        while index < len(formula):
            ch = formula[index]
            if ch == '(':
                group, index = parse_r(formula, index + 1, level + 1)
                quant, index = parse_quant(formula, index)
                for symbol in group:
                    prev = get_quant(elems, symbol)
                    elems[symbol] = prev + group[symbol] * quant
            elif ch.isalpha():
                symbol = formula[index:index+2]
                if symbol in periodic_table:
                    index += 2
                else:
                    symbol = formula[index:index+1]
                    if symbol in periodic_table:
                        index += 1
                    else:
                        # Unknown symbol for an element
                        raise FormulaError('invalid formula:', formula, index)
                quant, index = parse_quant(formula, index)
                prev = get_quant(elems, symbol)
                elems[symbol] = prev + quant
            elif ch == ')':
                if level == 0:
                    # Mismatched close parenthesis
                    raise FormulaError('invalid formula:', formula, index)
                level -= 1
                index += 1
                break
            else:
                # Illegal character: [^()0-9a-zA-Z] or decimal digit not
                # preceded by an element symbol or close parenthesis
                raise FormulaError('invalid formula:', formula, index)
        if level > 0 and level >= start_level:
            # Mismatched open parenthesis
            raise FormulaError('invalid formula:', formula, start_index - 1)
        return elems, index

    # Return the compound list of element symbols and
    # quantities. Each element in the compound list
    # will be a list in this form: ['symbol', quantity]
    elems, _ = parse_r(formula, 0, 0)
    return list(elems.items())

'''****************************************************************************
This function computes the molar mass of the molecule.
****************************************************************************'''
def compute_molar_mass(symbol_quantity_list, periodic_table):
    index = 0
    molar_mass= 0

    while index < len(symbol_quantity_list):
        product = (periodic_table[symbol_quantity_list[index][0]][1] * 
        symbol_quantity_list[index][1])
        molar_mass = molar_mass + product
        index += 1

    return molar_mass

'''****************************************************************************
This function dermines how many moles are in the molecule based on the given
mass.
****************************************************************************'''
def compute_moles(molar_mass, mass):
    moles = float (mass) / molar_mass

    return moles

'''****************************************************************************
This displays the moles per gram and amount of moles in the given mass.
****************************************************************************'''


def display(molar_mass, moles):
    print(colors.start_yellow + f"{round(molar_mass, 5)}" + colors.end + " grams/mole")
    print(colors.start_yellow + f"{round(moles, 5)}" + colors.end + " moles")

    repeat()

'''****************************************************************************
This function asks the user if they would like to repeat the program.
****************************************************************************'''
def repeat():
    answer = input("Would you like to compute another formula (y/n)? " + colors.start_cyan)
    if (answer.lower() == 'y'):
        main()
    else:
        exit()

'''****************************************************************************
This is the main function which initializes each variable and calls the other
functions
****************************************************************************'''
class colors:
    start_yellow = '\033[1;33m'
    start_cyan = "\033[0;36m"
    end = '\033[0m'

def main():
    formula = input(colors.end + 'Enter a chemical forula: ' + colors.start_cyan)
    mass = input(colors.end + 'Enter the mass in grams: '+ colors.start_cyan)

    periodic_table = make_periodic_table()
    symbol_quantity_list = parse_formula(formula, periodic_table)
    molar_mass = compute_molar_mass(symbol_quantity_list, periodic_table)
    moles = compute_moles(molar_mass, mass)
    display(molar_mass, moles)

    return 0

main()
