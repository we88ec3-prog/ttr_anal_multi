
void FUN_006f0220(undefined4 *param_1)

{
  char cVar1;
  uint *puVar2;
  char *pcVar3;
  undefined4 ****ppppuVar4;
  undefined4 in_ECX;
  char *in_EDX;
  uint uStack_e8;
  undefined4 ***local_cc [4];
  undefined4 local_bc;
  uint local_b8;
  _SYSTEMTIME local_b0;
  char local_a0 [132];
  uint local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915e1b;
  local_10 = ExceptionList;
  uStack_e8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_e8;
  ExceptionList = &local_10;
  local_1c = uStack_e8;
  puVar2 = &uStack_e8;
  if (in_EDX != (char *)0x0) {
    local_8 = 0;
    GetLocalTime(&local_b0);
    local_a0[0] = '\0';
    _memset(local_a0 + 1,0,0x7f);
    switch(in_ECX) {
    case 0:
      pcVar3 = "INFO";
      break;
    case 1:
      pcVar3 = "WARNING";
      break;
    case 2:
      pcVar3 = "ERROR";
      break;
    case 3:
      pcVar3 = "CRITICAL";
      break;
    default:
      pcVar3 = "UNKNOWN";
    }
    FUN_006f0490("[%4d-%2d-%2d][%02d:%02d:%02d][%s] ",local_b0.wYear,local_b0.wMonth,local_b0.wDay,
                 local_b0.wHour,local_b0.wMinute,local_b0.wSecond,pcVar3);
    pcVar3 = local_a0;
    local_b8 = 0xf;
    local_bc = 0;
    local_cc[0] = (undefined4 ***)((uint)local_cc[0] & 0xffffff00);
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(local_a0,(int)pcVar3 - (int)(local_a0 + 1));
    local_8 = CONCAT31(local_8._1_3_,1);
    pcVar3 = in_EDX;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401fc0(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
    FUN_00429630(1,10);
    ppppuVar4 = (undefined4 ****)local_cc[0];
    if (local_b8 < 0x10) {
      ppppuVar4 = local_cc;
    }
    (**(code **)(*(int *)*param_1 + 4))(ppppuVar4);
    puVar2 = (uint *)local_14;
    if (0xf < local_b8) {
      FUN_0089120c(local_cc[0]);
      puVar2 = (uint *)local_14;
    }
  }
  local_14 = (undefined1 *)puVar2;
  ExceptionList = local_10;
  __security_check_cookie(local_1c ^ (uint)&stack0xfffffffc);
  return;
}

