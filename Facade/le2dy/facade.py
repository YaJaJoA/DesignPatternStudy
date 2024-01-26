class itemNode:
    _name = None
    _value = None

    def __init__(self, name: str) -> None:
        self._name = name

    def setValue(self, value: str):
        self._value = value
        self.callMyName()

    def callMyName(self):
        print(f"Hi, my name is {self._name}, and prints '{self._value}'!")


class ProgramNode:
    _variables: dict[str, itemNode] = {}

    def __init__(self) -> None:
        pass

    def addVariable(self, variableName: str):
        self._variables[variableName] = itemNode(variableName)

    def setVariable(self, variableName: str, expression: str):
        self._variables[variableName].setValue(expression)


class ProgramNodeBuilder:
    _node = None

    def __init__(self) -> None:
        self.programnode = ProgramNode()
        self.programnode.addVariable("ID")
        self.programnode.setVariable("ID", "ADMIN")

        self.programnode.addVariable("PWD")
        self.programnode.setVariable("PWD", "P@ssw0rd")


if __name__ == "__main__":
    programnodebuilder = ProgramNodeBuilder()
