
void FUN_00713910(char *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 in_ECX;
  char local_28 [16];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (DAT_00fba814 != (int *)0x0) {
    iVar3 = _tolower((int)*param_1);
    cVar2 = (char)iVar3;
    if (((cVar2 != 'w') && (cVar2 != 'a')) && (cVar2 == 'r')) {
      iVar3 = FUN_00714c50(in_ECX,1);
      if (iVar3 != 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x2c));
        *(int *)(iVar3 + 0x54) = *(int *)(iVar3 + 0x54) + 1;
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x2c));
        if (*(int *)(iVar3 + 8) == 0) {
          iVar3 = FUN_00714c50(in_ECX,1);
        }
        *(undefined4 *)(iVar3 + 0x50) = 1;
        puVar4 = (undefined4 *)FUN_00891268(0x18);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          *puVar4 = StdPackage::vftable;
          *(undefined1 *)(puVar4 + 1) = 0;
          puVar4[2] = 0;
          puVar4[3] = 0;
          puVar4[4] = 0;
          puVar4[5] = 0;
        }
        piVar1 = DAT_00fba818;
        *(undefined1 *)(puVar4 + 1) = 0x72;
        puVar4[5] = iVar3;
        if (piVar1 != (int *)0x0) {
          local_14 = *(undefined4 *)(iVar3 + 0x18);
          local_18 = *(undefined4 *)(iVar3 + 0x14);
          local_c = *(undefined4 *)(iVar3 + 0x20);
          local_10 = *(undefined4 *)(iVar3 + 0x1c);
          (**(code **)(*piVar1 + 8))
                    (*(undefined4 *)(iVar3 + 0x48),*(undefined4 *)(iVar3 + 0x4c),local_28);
          iVar3 = 0;
          do {
            if (*(char *)((int)&local_18 + iVar3) != local_28[iVar3]) {
              iVar3 = 0;
              goto LAB_00713a38;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < 0x10);
        }
        goto LAB_00713a23;
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
  while (iVar3 = iVar3 + 1, iVar3 < 0x10) {
LAB_00713a38:
    if (*(char *)((int)&local_18 + iVar3) != '\0') goto LAB_00713a83;
  }
  cVar2 = (**(code **)*DAT_00fba818)(in_ECX,&local_18);
  if (cVar2 != '\0') {
    iVar3 = 0;
    while (*(char *)((int)&local_18 + iVar3) == local_28[iVar3]) {
      iVar3 = iVar3 + 1;
      if (0xf < iVar3) {
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
LAB_00713a83:
    (**(code **)(*DAT_00fba814 + 4))(in_ECX);
    (**(code **)*puVar4)(1);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_00713a23:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

