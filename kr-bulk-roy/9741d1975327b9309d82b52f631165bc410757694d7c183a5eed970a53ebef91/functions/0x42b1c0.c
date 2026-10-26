
void FUN_0042b1c0(byte *param_1,ushort *param_2,int *param_3,int *param_4,int *param_5)

{
  ushort uVar1;
  int *piVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  ushort *in_ECX;
  ushort *in_EDX;
  ushort *puVar6;
  int *unaff_EDI;
  bool bVar7;
  undefined4 uVar8;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00931b88;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = (int *)unaff_EDI[0x92];
  if (((byte)((uint)piVar2[10] >> 9) & 1) == *param_1) {
    puVar6 = in_EDX;
    if (7 < *(uint *)(in_EDX + 10)) {
      puVar6 = *(ushort **)in_EDX;
    }
    puVar4 = (ushort *)(unaff_EDI[0x93] + 0xe8);
    if (7 < *(uint *)(unaff_EDI[0x93] + 0xfc)) {
      puVar4 = *(ushort **)puVar4;
    }
    do {
      uVar1 = *puVar4;
      bVar7 = uVar1 < *puVar6;
      if (uVar1 != *puVar6) {
LAB_0042b257:
        iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_0042b25c;
      }
      if (uVar1 == 0) break;
      uVar1 = puVar4[1];
      bVar7 = uVar1 < puVar6[1];
      if (uVar1 != puVar6[1]) goto LAB_0042b257;
      puVar4 = puVar4 + 2;
      puVar6 = puVar6 + 2;
    } while (uVar1 != 0);
    iVar5 = 0;
LAB_0042b25c:
    if (iVar5 == 0) {
      puVar6 = param_2;
      if (7 < *(uint *)(param_2 + 10)) {
        puVar6 = *(ushort **)param_2;
      }
      puVar4 = (ushort *)(unaff_EDI[0x94] + 0xe8);
      if (7 < *(uint *)(unaff_EDI[0x94] + 0xfc)) {
        puVar4 = *(ushort **)puVar4;
      }
      do {
        uVar1 = *puVar4;
        bVar7 = uVar1 < *puVar6;
        if (uVar1 != *puVar6) {
LAB_0042b2ab:
          iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_0042b2b0;
        }
        if (uVar1 == 0) break;
        uVar1 = puVar4[1];
        bVar7 = uVar1 < puVar6[1];
        if (uVar1 != puVar6[1]) goto LAB_0042b2ab;
        puVar4 = puVar4 + 2;
        puVar6 = puVar6 + 2;
      } while (uVar1 != 0);
      iVar5 = 0;
LAB_0042b2b0:
      if (iVar5 == 0) {
        puVar6 = in_ECX;
        if (7 < *(uint *)(in_ECX + 10)) {
          puVar6 = *(ushort **)in_ECX;
        }
        puVar4 = (ushort *)(unaff_EDI[0x95] + 0xe8);
        if (7 < *(uint *)(unaff_EDI[0x95] + 0xfc)) {
          puVar4 = *(ushort **)puVar4;
        }
        do {
          uVar1 = *puVar4;
          bVar7 = uVar1 < *puVar6;
          if (uVar1 != *puVar6) {
LAB_0042b2fb:
            iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
            goto LAB_0042b300;
          }
          if (uVar1 == 0) break;
          uVar1 = puVar4[1];
          bVar7 = uVar1 < puVar6[1];
          if (uVar1 != puVar6[1]) goto LAB_0042b2fb;
          puVar4 = puVar4 + 2;
          puVar6 = puVar6 + 2;
        } while (uVar1 != 0);
        iVar5 = 0;
LAB_0042b300:
        if ((((iVar5 == 0) && (*param_3 == unaff_EDI[0x97])) && (*param_4 == unaff_EDI[0x98])) &&
           (*param_5 == unaff_EDI[0x99])) goto LAB_0042b4f9;
      }
    }
  }
  if ((*param_3 == -1) || (*param_4 == -1)) {
    (**(code **)(*piVar2 + 0x94))(0,uVar3);
    FUN_00757710();
    FUN_00757710();
    FUN_00757710();
    FUN_00757710();
  }
  else {
    (**(code **)(*piVar2 + 0x94))(1);
    (**(code **)(*(int *)unaff_EDI[0x92] + 0xa0))(*param_1);
    if (*param_1 == 0) {
      uVar8 = 0x32e;
    }
    else {
      uVar8 = 0x32f;
    }
    FUN_00585620(uVar8);
    FUN_00585330(uVar8);
    FUN_00757710();
    FUN_00757800(in_EDX);
    FUN_00757800(param_2);
    FUN_00757800(in_ECX);
    unaff_EDI[0x98] = *param_4;
    unaff_EDI[0x97] = *param_3;
    uVar8 = FUN_0040e460(&DAT_00bf2bf8);
    local_8 = 0;
    FUN_00757800(uVar8);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    *(int *)(unaff_EDI[0x93] + 0x154) = *param_5;
    *(int *)(unaff_EDI[0x94] + 0x154) = *param_5;
    *(int *)(unaff_EDI[0x95] + 0x154) = *param_5;
    *(int *)(unaff_EDI[0x96] + 0x154) = *param_5;
  }
  (**(code **)(*(int *)unaff_EDI[0x92] + 200))();
  (**(code **)(*unaff_EDI + 200))();
LAB_0042b4f9:
  ExceptionList = local_10;
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}

