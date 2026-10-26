
void FUN_006ea9e0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_a4 [19];
  undefined4 local_58;
  undefined1 local_54 [12];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar2 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  cVar1 = *(char *)(iVar2 + 0x309);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (cVar1 != '\0') {
    if (DAT_00fba7cc == 0) {
      iVar2 = FUN_00891268(0x1380);
      if (iVar2 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    iVar2 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    cVar1 = *(char *)(iVar2 + 0x29c);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if (cVar1 == '\0') {
      if (DAT_00fba7cc == 0) {
        iVar2 = FUN_00891268(0x1380);
        if (iVar2 == 0) {
          DAT_00fba7cc = 0;
        }
        else {
          DAT_00fba7cc = FUN_006df3d0();
        }
      }
      cVar1 = FUN_006e0e20(DAT_00fba7cc);
      if (cVar1 != '\0') {
        uVar3 = FUN_006df6d0();
        iVar2 = FUN_006e03c0(uVar3);
        if (*(int *)(iVar2 + 0x30) != 0) {
          uVar3 = FUN_006dfd60();
          iVar2 = FUN_006ed930(uVar3);
          uVar3 = FUN_006df6d0();
          iVar4 = FUN_006e0500(uVar3);
          if ((iVar2 != iVar4) && (iVar2 = FUN_006eac20(iVar2,&local_58), -1 < iVar2)) {
            puVar5 = (undefined4 *)FUN_006ea4e0(local_54);
            puVar6 = local_a4;
            for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
              *puVar6 = *puVar5;
              puVar5 = puVar5 + 1;
              puVar6 = puVar6 + 1;
            }
            local_44 = 2;
            local_40 = 2;
            local_3c = 2;
            local_38 = 2;
            local_34 = 2;
            local_30 = 2;
            local_2c = 2;
            local_28 = 2;
            local_24 = 2;
            local_20 = 2;
            local_1c = 2;
            local_18 = 2;
            local_14 = 2;
            local_10 = 2;
            local_a4[0] = local_58;
            local_48 = 1;
            iVar2 = FUN_006e3830(local_a4,local_a4);
            if (-1 < iVar2) {
              iVar2 = FUN_006e4f90(local_a4,0,0,0,0);
              if (iVar2 == -0x7fffbffc) {
                uVar3 = FUN_006df6d0();
                FUN_006df5a0(uVar3);
                __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
                return;
              }
              if (iVar2 < 0) {
                FUN_006e9ae0();
                FUN_006e71f0(0,0);
              }
            }
          }
        }
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

