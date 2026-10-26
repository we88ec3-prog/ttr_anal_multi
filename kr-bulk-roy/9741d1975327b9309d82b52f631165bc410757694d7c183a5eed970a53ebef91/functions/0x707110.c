
int FUN_00707110(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == param_2) {
    iVar3 = 0;
  }
  else if (*(char *)(param_2 + 6) == '\0') {
    iVar3 = FUN_006f7dd0();
    if (iVar3 < 1) {
      iVar3 = (-(uint)((*(int *)(param_2 + 8) - *(int *)(param_2 + 0xc) & 0xfffffff0U) != 0) &
              0xfffffffe) + 3;
    }
    else {
      iVar3 = 2;
    }
  }
  else if (*(char *)(param_2 + 6) == '\x01') {
    iVar3 = 1;
  }
  else {
    iVar3 = 3;
  }
  iVar1 = FUN_006f5170();
  if (iVar1 == 0) {
    FUN_006f5f30(param_1,"too many arguments to resume");
  }
  if (iVar3 != 1) {
    FUN_006f5580(param_1,"cannot resume %s coroutine",(&PTR_s_running_00c0bc58)[iVar3]);
    return -1;
  }
  FUN_006f51d0();
  *(undefined2 *)(param_2 + 0x34) = *(undefined2 *)(param_1 + 0x34);
  iVar3 = FUN_006fe6d0();
  if ((iVar3 != 0) && (iVar3 != 1)) {
    FUN_006f51d0();
    return -1;
  }
  iVar3 = *(int *)(param_2 + 8);
  iVar1 = *(int *)(param_2 + 0xc);
  iVar2 = FUN_006f5170();
  if (iVar2 == 0) {
    FUN_006f5f30(param_1,"too many results to resume");
  }
  FUN_006f51d0();
  return iVar3 - iVar1 >> 4;
}

