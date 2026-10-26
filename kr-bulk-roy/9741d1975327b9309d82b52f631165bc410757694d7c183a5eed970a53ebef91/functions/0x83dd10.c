
bool FUN_0083dd10(void)

{
  int in_EAX;
  int iVar1;
  
  if (*(int *)(in_EAX + 0x454) != 0) {
    (**(code **)(**(int **)(in_EAX + 0xec) + 400))
              (*(int **)(in_EAX + 0xec),0,*(int *)(in_EAX + 0x454),0,*(undefined4 *)(in_EAX + 0x458)
              );
    (**(code **)(**(int **)(in_EAX + 0xec) + 0x164))(*(int **)(in_EAX + 0xec),0x102);
    iVar1 = (**(code **)(**(int **)(in_EAX + 0xec) + 0x144))(*(int **)(in_EAX + 0xec),4,0,2);
    return -1 < iVar1;
  }
  return false;
}

