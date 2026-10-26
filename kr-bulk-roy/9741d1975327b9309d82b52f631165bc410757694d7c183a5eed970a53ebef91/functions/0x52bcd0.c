
undefined4 FUN_0052bcd0(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int in_EAX;
  int in_ECX;
  uint uVar3;
  int *piVar4;
  
  FUN_008438c0(&param_1);
  if (in_ECX != *(int *)(in_EAX + 8)) {
    iVar1 = *(int *)(in_ECX + 0x10);
    uVar3 = 0;
    if (*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 0xc) >> 2 != 0) {
      piVar2 = *(int **)(iVar1 + 0xc);
      piVar4 = piVar2;
      do {
        if ((*(int *)*piVar4 == param_2) && (*(ushort *)((int *)*piVar4 + 2) == param_3)) {
          return *(undefined4 *)(piVar2[uVar3] + 0xc);
        }
        uVar3 = uVar3 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar3 < (uint)(*(int *)(iVar1 + 0x10) - (int)piVar2 >> 2));
    }
  }
  return 0;
}

