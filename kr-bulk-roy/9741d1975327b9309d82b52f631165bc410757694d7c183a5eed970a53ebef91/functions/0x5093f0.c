
void FUN_005093f0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    while( true ) {
      FUN_00542210();
      piVar1 = (int *)FUN_0050b4b0();
      iVar3 = 0;
      if ((int *)*piVar1 != (int *)0x0) {
        iVar3 = *(int *)*piVar1;
      }
      uVar2 = piVar1[2];
      if (*(uint *)(iVar3 + 8) <= uVar2) {
        uVar2 = uVar2 - *(uint *)(iVar3 + 8);
      }
      piVar1 = *(int **)(*(int *)(iVar3 + 4) + uVar2 * 4);
      if ((*piVar1 == param_2) && (piVar1[1] == param_3)) break;
      uVar4 = uVar4 + 1;
      if (*(uint *)(param_1 + 0x10) <= uVar4) {
        return;
      }
    }
    FUN_00542210();
    FUN_0050b4b0();
    FUN_0050b120(param_1);
  }
  return;
}

