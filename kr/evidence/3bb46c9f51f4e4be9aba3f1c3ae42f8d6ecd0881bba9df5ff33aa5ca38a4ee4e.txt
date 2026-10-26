
void FUN_004dff30(uint param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  undefined4 uVar3;
  int local_c;
  
  iVar2 = param_1;
  if (in_EAX == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_006edc70(&DAT_00c0ced0);
  }
  iVar1 = param_1 + 8;
  param_1 = (uint)*(ushort *)(in_EAX + 4);
  FUN_0082ef00(&param_1);
  if (local_c == *(int *)(iVar2 + 0xc)) {
    uVar3 = FUN_0057ef20();
    FUN_0082f200(iVar1,uVar3);
    return;
  }
  FUN_006edb60(&DAT_00c0cef0,param_1);
  return;
}

