
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0088c1ae(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,double param_7)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint local_5c;
  undefined2 local_58 [8];
  undefined4 local_48;
  undefined4 local_44;
  char local_3c [52];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5c;
  bVar1 = param_7 < 0.0;
  if (bVar1) {
    param_7 = -param_7;
  }
  local_5c = 0;
  if (!NAN(param_7) && 1e+35 < param_7 != (param_7 == 1e+35)) {
    do {
      if (4999 < local_5c) break;
      local_5c = local_5c + 10;
      param_7 = param_7 / 10000000000.0;
    } while (1e+35 <= param_7);
  }
  local_44 = 7;
  local_48 = 0;
  local_58[0] = 0;
  local_8 = 0;
  iVar2 = _sprintf_s(local_3c,0x28,"%.0Lf");
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      FUN_004303a0();
      FUN_00440010();
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  FUN_004303a0();
  FUN_00440010();
  FUN_00402110(local_58);
  Putmfld(param_1,param_2,param_3,param_4,param_5,param_6,bVar1);
  FUN_00402a00();
  FUN_0089dbbc();
  return;
}

