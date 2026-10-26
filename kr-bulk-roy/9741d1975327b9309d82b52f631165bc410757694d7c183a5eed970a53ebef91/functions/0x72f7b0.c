
void FUN_0072f7b0(int param_1,FILE *param_2)

{
  int iVar1;
  undefined4 ***pppuVar2;
  undefined4 ***pppuVar3;
  int unaff_ESI;
  undefined *puVar4;
  undefined1 local_50 [4];
  undefined4 **local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00915b10;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = (undefined4 **)((uint)local_4c[0] & 0xffffff00);
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffffff00);
  local_8 = 1;
  FUN_0072de70(local_4c,local_14);
  FUN_0072de70(local_30);
  local_50[0] = 0x22;
  iVar1 = FUN_00440930(param_1 + 0x30,local_50,1);
  if (iVar1 == -1) {
    if (param_2 != (FILE *)0x0) {
      pppuVar3 = (undefined4 ***)local_30[0];
      if (local_1c < 0x10) {
        pppuVar3 = local_30;
      }
      pppuVar2 = (undefined4 ***)local_4c[0];
      if (local_38 < 0x10) {
        pppuVar2 = local_4c;
      }
      _fprintf(param_2,"%s=\"%s\"",pppuVar2,pppuVar3);
    }
    if (unaff_ESI == 0) goto LAB_0072f90c;
    FUN_00401ed0(local_4c,0,0xffffffff);
    FUN_00401fc0(&DAT_00c44c6c,2);
    FUN_00401ed0(local_30,0,0xffffffff);
    puVar4 = &DAT_00c411ac;
  }
  else {
    if (param_2 != (FILE *)0x0) {
      pppuVar3 = (undefined4 ***)local_30[0];
      if (local_1c < 0x10) {
        pppuVar3 = local_30;
      }
      pppuVar2 = (undefined4 ***)local_4c[0];
      if (local_38 < 0x10) {
        pppuVar2 = local_4c;
      }
      _fprintf(param_2,"%s=\'%s\'",pppuVar2,pppuVar3);
    }
    if (unaff_ESI == 0) goto LAB_0072f90c;
    FUN_00401ed0(local_4c,0,0xffffffff);
    FUN_00401fc0(&DAT_00c44c78,2);
    FUN_00401ed0(local_30,0,0xffffffff);
    puVar4 = &DAT_00bed1cc;
  }
  FUN_00401fc0(puVar4,1);
LAB_0072f90c:
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffffff00);
  if (0xf < local_38) {
    FUN_0089120c(local_4c[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

