
void FUN_006fb5d0(void)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined8 *unaff_ESI;
  undefined1 local_80 [28];
  char local_64 [32];
  uint local_44;
  
  local_44 = DAT_00d61f20 ^ (uint)local_80;
  if (*(int *)(unaff_ESI + 1) != 3) {
    __security_check_cookie(local_44 ^ (uint)local_80);
    return;
  }
  _sprintf(local_64,"%.14g",*unaff_ESI);
  pcVar2 = local_64;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar3 = FUN_006fec70();
  *(undefined4 *)unaff_ESI = uVar3;
  *(undefined4 *)(unaff_ESI + 1) = 4;
  __security_check_cookie(local_44 ^ (uint)local_80);
  return;
}

