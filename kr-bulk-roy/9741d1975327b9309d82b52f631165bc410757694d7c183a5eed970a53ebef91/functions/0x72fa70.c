
void FUN_0072fa70(FILE *param_1,int param_2)

{
  int *piVar1;
  undefined4 ***pppuVar2;
  int in_ECX;
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917e28;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(char *)(in_ECX + 0x44) == '\0') {
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffffff00);
    local_8 = 0;
    FUN_0072de70(local_30,local_14);
    pppuVar2 = (undefined4 ***)local_30[0];
    if (local_1c < 0x10) {
      pppuVar2 = local_30;
    }
    _fprintf(param_1,"%s",pppuVar2);
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  else {
    _fprintf(param_1,"\n");
    if (0 < param_2) {
      do {
        _fprintf(param_1,"    ");
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    piVar1 = (int *)(in_ECX + 0x20);
    if (0xf < *(uint *)(in_ECX + 0x34)) {
      piVar1 = (int *)*piVar1;
    }
    _fprintf(param_1,"<![CDATA[%s]]>\n",piVar1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

