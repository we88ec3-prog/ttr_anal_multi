
void FUN_004dfbc0(void)

{
  int in_EAX;
  int in_ECX;
  int iVar1;
  
  FUN_0082ef00(&stack0x00000004);
  if (in_ECX != *(int *)(in_EAX + 0xc)) {
    iVar1 = 0;
    do {
      (**(code **)(*DAT_00fba7a4 + 0x1c))(iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 3);
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x14))();
    if (*(undefined4 **)(in_ECX + 0x10) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x10))(1);
      *(undefined4 *)(in_ECX + 0x10) = 0;
    }
    FUN_007b6890(in_EAX + 8,&stack0x00000004,in_ECX);
  }
  return;
}

