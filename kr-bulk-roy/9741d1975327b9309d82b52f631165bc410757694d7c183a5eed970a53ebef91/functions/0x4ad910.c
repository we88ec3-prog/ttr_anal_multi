
void FUN_004ad910(int *param_1)

{
  char cVar1;
  char *pcVar2;
  char local_14 [12];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  __itoa_s(*param_1,local_14,0xc,10);
  pcVar2 = local_14;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(local_14,(int)pcVar2 - (int)(local_14 + 1));
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

