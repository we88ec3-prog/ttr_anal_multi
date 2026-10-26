
void FUN_0066a020(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int *piVar5;
  
  FUN_00755e50();
  FUN_00615fc0(100);
  FUN_00615fc0(400);
  FUN_0044dd40(0x12d);
  FUN_0044dd40(0x262);
  piVar1 = (int *)(in_ECX + 0x104);
  FUN_006686e0();
  FUN_0066b820();
  FUN_00615fc0(0x83e);
  FUN_00615fc0(0x8a2);
  FUN_00615fc0(0x906);
  piVar5 = (int *)(in_ECX + 0x160);
  FUN_0046b6f0(0x843);
  FUN_0046b6f0(0x8a7);
  FUN_0046b6f0(0x90b);
  (**(code **)(**(int **)(in_ECX + 0x10c) + 0x198))(0x83f);
  (**(code **)(**(int **)(in_ECX + 0x110) + 0x198))(0x8a3);
  (**(code **)(**(int **)(in_ECX + 0x114) + 0x198))(0x907);
  *(undefined4 *)(*(int *)(in_ECX + 0x10c) + 0x2ac) = 0;
  *(undefined4 *)(*(int *)(in_ECX + 0x110) + 0x2ac) = 1;
  *(undefined4 *)(*(int *)(in_ECX + 0x114) + 0x2ac) = 2;
  *(int *)(*(int *)(in_ECX + 0x10c) + 0x2a8) = in_ECX;
  *(int *)(*(int *)(in_ECX + 0x110) + 0x2a8) = in_ECX;
  *(int *)(*(int *)(in_ECX + 0x114) + 0x2a8) = in_ECX;
  *(undefined4 *)(*(int *)(in_ECX + 0x108) + 0x144) = 0x14;
  *(undefined4 *)(*(int *)(in_ECX + 0xfc) + 0x144) = 8;
  *(undefined4 *)(*(int *)(in_ECX + 0x100) + 0x144) = 0x14;
  *(undefined4 *)(*piVar1 + 0x130) = 200;
  *(undefined1 *)(*piVar1 + 0x148) = 1;
  *(undefined1 *)(*piVar1 + 0xca) = 1;
  *(undefined1 *)(*(int *)(in_ECX + 0xfc) + 0xca) = 1;
  *(undefined1 *)(*(int *)(in_ECX + 0x100) + 0xca) = 1;
  iVar4 = 3;
  do {
    iVar2 = *piVar5;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar2 + 0xa4) = 1;
    iVar2 = *piVar5;
    if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
      iVar3 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
      if (iVar3 == 0xbf6b) {
        *(undefined1 *)(*(int *)(iVar2 + 0x94) + 0x4c) = 1;
      }
    }
    piVar5 = piVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}

