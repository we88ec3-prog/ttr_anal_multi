
void FUN_008cf630(undefined4 param_1,short *param_2,int param_3,int param_4)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined1 local_88 [24];
  int local_70;
  undefined2 local_10;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((param_2[1] != 0) && (*param_2 != 0)) {
    iVar4 = FUN_008ce8e0(local_88,param_2,param_1,param_3);
    if (iVar4 == 0) {
      iVar4 = *(int *)(local_70 + 200);
      iVar1 = *(int *)(local_70 + 0x194);
      bVar3 = false;
      lVar2 = (longlong)*(int *)(param_3 + 0x1a0) * (longlong)iVar1;
      lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
      uVar5 = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000;
      uVar8 = uVar5 + 0x20 & 0xffffffc0;
      if ((uVar8 != 0) && (uVar5 != uVar8)) {
        bVar3 = true;
        uVar6 = FUN_008b7dc0(iVar1,uVar8,uVar5);
        iVar7 = iVar4;
        if ((int)uVar8 < (int)uVar5) {
          iVar7 = (int)((ulonglong)((longlong)iVar4 * -0x51eb851f) >> 0x20);
          iVar7 = iVar4 + ((iVar7 >> 4) - (iVar7 >> 0x1f));
        }
        FUN_008cdec0(local_70,iVar7,uVar6,0,0);
      }
      local_10 = 0x101;
      if ((param_4 == 2) || (param_4 == 3)) {
        local_e = 1;
      }
      else {
        local_e = 0;
      }
      if ((param_4 == 2) || (param_4 == 4)) {
        local_d = 1;
      }
      else {
        local_d = 0;
      }
      local_c = param_4 != 1;
      iVar7 = 0;
      do {
        FUN_008ce830();
        FUN_008ceb30(local_88);
        FUN_008ce610(local_70,iVar7);
        FUN_008cee10();
        if (iVar7 == 1) {
          FUN_008cef50();
        }
        FUN_008cf080();
        FUN_008cf180();
        FUN_008cf3c0();
        FUN_008ce880(iVar7);
        if (bVar3) {
          FUN_008cdec0(local_70,iVar4,iVar1,0,0);
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < 2);
    }
    FUN_008ce7a0();
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

