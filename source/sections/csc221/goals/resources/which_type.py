# Match each of the following literals with their appropriate data type names.
# Select from: String, Boolean, Integer, Float, List, Tuple, or Dictionary
#
#
def data_type_name(val):
    if isinstance(val, bool):
        return 'Boolean'
    if isinstance(val, int):
        return 'Integer'
    if isinstance(val, float):
        return 'Float'
    if isinstance(val, str):
        return 'String'
    if isinstance(val, list):
        return 'List'
    if isinstance(val, tuple):
        return 'Tuple'
    if isinstance(val, dict):
        return 'Dictionary'
    raise ValueError(f'{val} is not one of our known types.')

literals = [
    'ACC',
    3.14159,
    [1, 2, 3],
    -32_378_245,
    ('a', 'b', 'c'),
    True,
    {'count': 5, 'color': 0xA40785}
]

for literal in literals:
    print(f'{literal} is a {data_type_name(literal)}.')
