
void FUN_0070e420(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined1 local_298 [4];
  undefined4 local_294;
  undefined4 local_290;
  int local_288;
  undefined4 local_284;
  undefined4 local_280;
  undefined4 local_27c;
  int local_278;
  undefined4 local_274;
  undefined4 local_270;
  undefined4 local_26c;
  undefined4 local_264;
  undefined4 local_25c;
  int local_250;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)local_298;
  local_25c = param_3;
  pcVar2 = param_4;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_006fec70(param_1,param_4,(int)pcVar2 - (int)(param_4 + 1));
  FUN_006ff2c0(param_1);
  FUN_0070dfb0(local_298);
  *(undefined1 *)(local_250 + 0x4a) = 2;
  local_290 = local_294;
  if (local_278 == 0x11f) {
    local_288 = FUN_006ffec0(&local_280);
  }
  else {
    local_288 = local_278;
    local_284 = local_274;
    local_280 = local_270;
    local_27c = local_26c;
    local_278 = 0x11f;
  }
  FUN_00711b20(local_298);
  if (local_288 != 0x11f) {
    uVar3 = FUN_006f7c30(local_264,"\'%s\' expected","<eof>");
                    /* WARNING: Subroutine does not return */
    FUN_006ff130(local_298,uVar3,local_288);
  }
  FUN_0070e110(local_298);
  __security_check_cookie(local_c ^ (uint)local_298);
  return;
}

