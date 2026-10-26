
void FUN_007f23b0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  int *piVar7;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092b9ae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x7c) != 0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8 = 0xffffffff;
    piVar1 = *(int **)(in_ECX + 0x90);
    iVar6 = DAT_00fb7740;
    for (piVar7 = *(int **)(in_ECX + 0x8c); DAT_00fb7740 = iVar6, piVar7 != piVar1;
        piVar7 = piVar7 + 2) {
      iVar6 = *piVar7;
      iVar2 = piVar7[1];
      piVar3 = (int *)(&DAT_00fb7778)[iVar6 * 4];
      local_14 = iVar2;
      if (&local_14 < piVar3) {
        piVar4 = (int *)(&DAT_00fb7774)[iVar6 * 4];
        if (&local_14 < piVar4) goto LAB_007f247c;
        if (piVar3 == (int *)(&DAT_00fb777c)[iVar6 * 4]) {
          FUN_0079bf10();
        }
        if ((undefined4 *)(&DAT_00fb7778)[iVar6 * 4] != (undefined4 *)0x0) {
          *(undefined4 *)(&DAT_00fb7778)[iVar6 * 4] =
               *(undefined4 *)((&DAT_00fb7774)[iVar6 * 4] + ((int)&local_14 - (int)piVar4 >> 2) * 4)
          ;
        }
      }
      else {
LAB_007f247c:
        if (piVar3 == (int *)(&DAT_00fb777c)[iVar6 * 4]) {
          FUN_0079bf10();
        }
        if ((int *)(&DAT_00fb7778)[iVar6 * 4] != (int *)0x0) {
          *(int *)(&DAT_00fb7778)[iVar6 * 4] = iVar2;
        }
      }
      (&DAT_00fb7778)[iVar6 * 4] = (&DAT_00fb7778)[iVar6 * 4] + 4;
      iVar6 = DAT_00fb7740;
    }
    iVar5 = (**(code **)(*(int *)(in_ECX + 0x84) + 4))();
    iVar2 = *(int *)(iVar5 * 0x2004 + 0x2000 + iVar6);
    iVar6 = iVar5 * 0x2004 + iVar6;
    if (iVar2 < 0x800) {
      *(int *)(iVar6 + iVar2 * 4) = in_ECX + 0x84;
      piVar1 = (int *)(iVar6 + 0x2000);
      *piVar1 = *piVar1 + 1;
    }
  }
  ExceptionList = local_10;
  return;
}

