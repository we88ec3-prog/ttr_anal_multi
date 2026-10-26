
void FUN_006678e0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int local_8;
  
  FUN_00755e50();
  FUN_00615fc0(100);
  FUN_00615fc0(400);
  FUN_00615fc0(1000);
  FUN_0043c570(300);
  FUN_0043c570(0x259);
  FUN_006686e0();
  FUN_00615fc0(500);
  FUN_0043c570(0x1fe);
  FUN_00615fc0(0x83e);
  FUN_00615fc0(0x8a2);
  FUN_00615fc0(0x906);
  piVar3 = (int *)(in_ECX + 0x124);
  FUN_0046b6f0(0x843);
  FUN_0046b6f0(0x8a7);
  FUN_0046b6f0(0x90b);
  (**(code **)(**(int **)(in_ECX + 0x118) + 0x198))(0x83f);
  (**(code **)(**(int **)(in_ECX + 0x11c) + 0x198))(0x8a3);
  (**(code **)(**(int **)(in_ECX + 0x120) + 0x198))(0x907);
  local_8 = 3;
  do {
    iVar1 = *piVar3;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar1 + 0xa4) = 1;
    iVar1 = *piVar3;
    if ((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) {
      iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))();
      if (iVar2 == 0xbf6b) {
        *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
      }
    }
    piVar3 = piVar3 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return;
}

