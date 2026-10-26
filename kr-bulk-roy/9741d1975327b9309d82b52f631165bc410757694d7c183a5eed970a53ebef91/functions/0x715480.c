
void FUN_00715480(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *unaff_ESI;
  int *unaff_EDI;
  undefined8 local_124;
  int local_118 [3];
  char local_10c [260];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (unaff_ESI != (int *)0x0) {
    local_118[1] = 0;
    (**(code **)*unaff_ESI)(local_118 + 2,2);
    uVar4 = local_118[2] & 0xffff;
    (**(code **)*unaff_ESI)(local_10c,uVar4);
    pcVar1 = *(code **)(*unaff_ESI + 4);
    local_10c[uVar4] = '\0';
    cVar2 = (*pcVar1)();
    if ((cVar2 == '\x02') || (cVar2 == '\x01')) {
      _strcpy_s((char *)(unaff_EDI + 3),0x100,local_10c);
      (**(code **)*unaff_ESI)(local_118,4);
      (**(code **)*unaff_ESI)(&local_124,8);
      iVar5 = 0;
      *(undefined8 *)(unaff_EDI + 0x44) = local_124;
      if (0 < local_118[0]) {
        do {
          local_118[2] = 0;
          iVar3 = FUN_00715c60(unaff_ESI,local_118 + 2);
          if ((iVar3 == 0) || (local_118[2] != 0)) {
            local_118[1] = 1;
            break;
          }
          (**(code **)(*unaff_EDI + 0x30))(iVar3);
          iVar5 = iVar5 + 1;
        } while (iVar5 < local_118[0]);
      }
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

