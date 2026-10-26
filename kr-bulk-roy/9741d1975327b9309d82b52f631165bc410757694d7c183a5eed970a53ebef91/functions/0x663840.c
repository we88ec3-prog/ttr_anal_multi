
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00663840(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_10;
  
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  piVar3 = (int *)(param_1 + 0x160);
  local_10 = 0x10;
  do {
    piVar2 = (int *)*piVar3;
    iVar1 = piVar2[0xa7];
    if (iVar1 == -1) {
LAB_006638f2:
      (**(code **)(*piVar2 + 0x19c))(0xffffffff,0xffffffff,0,0);
    }
    else {
      if ((_DAT_00fe1c4c & 1) == 0) {
        _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
        FUN_004ff560();
        _atexit((_func_4879 *)&DAT_00bced40);
      }
      if (((&DAT_00fe1ca0)[iVar1 * 8] == 0) || ((&DAT_00fe1ca4)[iVar1 * 4] == 0)) {
        piVar2 = (int *)*piVar3;
        goto LAB_006638f2;
      }
      (**(code **)(*(int *)*piVar3 + 0x19c))
                ((&DAT_00fe1ca0)[iVar1 * 8],(&DAT_00fe1ca4)[iVar1 * 4],(&DAT_00fe1c98)[iVar1 * 4],
                 (&DAT_00fe1c9c)[iVar1 * 4]);
    }
    iVar1 = *piVar3;
    piVar3 = piVar3 + 1;
    local_10 = local_10 + -1;
    *(undefined4 *)(iVar1 + 0x298) = param_2;
    if (local_10 == 0) {
      return;
    }
  } while( true );
}

