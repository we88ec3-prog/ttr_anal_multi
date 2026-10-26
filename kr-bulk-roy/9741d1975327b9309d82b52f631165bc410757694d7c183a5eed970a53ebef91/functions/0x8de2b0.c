
int FUN_008de2b0(int param_1,char param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  uint in_EAX;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  void *pvVar7;
  uint in_ECX;
  uint uVar8;
  int in_EDX;
  uint *unaff_EDI;
  int local_8;
  
  uVar1 = *(undefined4 *)(param_1 + 0x1c);
  local_8 = 0;
  if (in_EAX < 3) {
    unaff_EDI[1] = in_EAX;
    if (in_EAX == 0) {
      if (0xe5 < in_ECX) goto LAB_008de412;
      pvVar7 = (void *)FUN_008bc7d0(uVar1,2,0);
      unaff_EDI[2] = (uint)pvVar7;
      if (local_8 != 0) goto LAB_008de546;
      FID_conflict__memcpy(pvVar7,&DAT_00be9930,in_ECX * 2);
    }
    else if (in_EAX == 1) {
      if (0xa6 < in_ECX) goto LAB_008de412;
      pvVar7 = (void *)FUN_008bc7d0(uVar1,2,0);
      unaff_EDI[2] = (uint)pvVar7;
      if (local_8 != 0) goto LAB_008de546;
      FID_conflict__memcpy(pvVar7,&DAT_00be9b00,in_ECX * 2);
    }
    else {
      if ((in_EAX != 2) || (0x57 < in_ECX)) {
LAB_008de412:
        local_8 = 3;
        goto LAB_008de546;
      }
      pvVar7 = (void *)FUN_008bc7d0(uVar1,2,0);
      unaff_EDI[2] = (uint)pvVar7;
      if (local_8 != 0) goto LAB_008de546;
      FID_conflict__memcpy(pvVar7,&DAT_00be9c50,in_ECX * 2);
    }
  }
  else {
    unaff_EDI[1] = in_EAX + in_EDX;
    local_8 = FUN_008b97e0(param_1,in_EAX + in_EDX);
    if (local_8 != 0) goto LAB_008de546;
    uVar3 = FUN_008b9a40(param_1,&local_8);
    *unaff_EDI = uVar3 & 0xff;
    if (local_8 != 0) goto LAB_008de546;
    puVar4 = (undefined2 *)FUN_008bc7d0(uVar1,2,0);
    unaff_EDI[2] = (uint)puVar4;
    if (local_8 != 0) goto LAB_008de546;
    *puVar4 = 0;
    if (*unaff_EDI == 0) {
      if (in_ECX != 0) {
        local_8 = FUN_008babe0(param_1,in_ECX * 2 + -2);
        if (local_8 != 0) goto LAB_008de546;
        uVar3 = 1;
        if (1 < in_ECX) {
          do {
            uVar2 = FUN_008b9960(param_1);
            *(undefined2 *)(unaff_EDI[2] + uVar3 * 2) = uVar2;
            uVar3 = uVar3 + 1;
          } while (uVar3 < in_ECX);
        }
        FUN_008baca0(param_1);
      }
    }
    else {
      if (1 < *unaff_EDI - 1) goto LAB_008de412;
      uVar3 = 1;
      if (1 < in_ECX) {
        do {
          uVar5 = FUN_008b9ab0(param_1,&local_8);
          uVar5 = uVar5 & 0xffff;
          if (local_8 != 0) goto LAB_008de546;
          if (*unaff_EDI == 2) {
            uVar6 = FUN_008b9ab0(param_1,&local_8);
            uVar6 = uVar6 & 0xffff;
          }
          else {
            uVar6 = FUN_008b9a40(param_1,&local_8);
            uVar6 = uVar6 & 0xff;
          }
          if (local_8 != 0) goto LAB_008de546;
          if (0xffff - uVar6 < uVar5) {
            uVar6 = 0xffff - uVar5;
          }
          uVar8 = 0;
          while( true ) {
            if (in_ECX <= uVar3) goto LAB_008de3f2;
            if (uVar6 < uVar8) break;
            *(short *)(unaff_EDI[2] + uVar3 * 2) = (short)uVar5;
            uVar3 = uVar3 + 1;
            uVar8 = uVar8 + 1;
            uVar5 = uVar5 + 1;
          }
        } while (uVar3 < in_ECX);
      }
    }
  }
LAB_008de3f2:
  if (param_2 != '\0') {
    local_8 = FUN_008de1d0(uVar1);
  }
  if (local_8 == 0) {
    return 0;
  }
LAB_008de546:
  FUN_008b9f80(uVar1,unaff_EDI[2]);
  unaff_EDI[2] = 0;
  FUN_008b9f80(uVar1,unaff_EDI[3]);
  unaff_EDI[3] = 0;
  *unaff_EDI = 0;
  unaff_EDI[1] = 0;
  unaff_EDI[2] = 0;
  return local_8;
}

