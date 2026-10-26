
void FUN_006ee380(int param_1)

{
  HANDLE *ppvVar1;
  HANDLE *ppvVar2;
  byte in_AL;
  HANDLE pvVar3;
  uint uVar4;
  int iVar5;
  uint local_c;
  HANDLE local_8;
  
  if (*(char *)(param_1 + 1) == '\0') {
    uVar4 = (uint)in_AL;
    *(byte *)(param_1 + 1) = in_AL;
    local_c = 0;
    if (in_AL != 0) {
      do {
        pvVar3 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
        ppvVar1 = *(HANDLE **)(param_1 + 8);
        local_8 = pvVar3;
        if (&local_8 < ppvVar1) {
          ppvVar2 = *(HANDLE **)(param_1 + 4);
          if (&local_8 < ppvVar2) goto LAB_006ee400;
          if (ppvVar1 == *(HANDLE **)(param_1 + 0xc)) {
            FUN_00797930();
          }
          if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 8) =
                 *(undefined4 *)(*(uint *)(param_1 + 4) + ((int)&local_8 - (int)ppvVar2 >> 2) * 4);
          }
        }
        else {
LAB_006ee400:
          if (ppvVar1 == *(HANDLE **)(param_1 + 0xc)) {
            FUN_00797930();
          }
          if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 8) = pvVar3;
          }
        }
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 4;
        pvVar3 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
        ppvVar1 = *(HANDLE **)(param_1 + 0x18);
        local_8 = pvVar3;
        if (&local_8 < ppvVar1) {
          ppvVar2 = *(HANDLE **)(param_1 + 0x14);
          if (&local_8 < ppvVar2) goto LAB_006ee465;
          if (ppvVar1 == *(HANDLE **)(param_1 + 0x1c)) {
            FUN_00797930();
          }
          if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 0x18) =
                 *(undefined4 *)(*(int *)(param_1 + 0x14) + ((int)&local_8 - (int)ppvVar2 >> 2) * 4)
            ;
          }
        }
        else {
LAB_006ee465:
          if (ppvVar1 == *(HANDLE **)(param_1 + 0x1c)) {
            FUN_00797930();
          }
          if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
            **(undefined4 **)(param_1 + 0x18) = pvVar3;
          }
        }
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 4;
        FUN_0085df00();
        local_c = local_c + 1;
      } while (local_c < uVar4);
    }
    if (uVar4 != 0) {
      iVar5 = 0;
      do {
        __beginthread(FUN_006ee540,0,(void *)(*(int *)(param_1 + 0x24) + iVar5));
        iVar5 = iVar5 + 0xc;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
  }
  return;
}

