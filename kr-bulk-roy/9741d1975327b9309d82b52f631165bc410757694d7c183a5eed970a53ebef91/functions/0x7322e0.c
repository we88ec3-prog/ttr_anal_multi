
void FUN_007322e0(int *param_1,undefined4 *param_2)

{
  byte bVar1;
  uint uVar2;
  void **ppvVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  int *piVar8;
  int *in_ECX;
  byte *pbVar9;
  bool bVar10;
  undefined1 auStack_7c [2];
  char cStack_7a;
  char cStack_79;
  int *local_78;
  undefined4 *local_74;
  int *local_70;
  int iStack_6c;
  undefined **appuStack_68 [19];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0091f3d8;
  local_1c = DAT_00d61f20 ^ (uint)auStack_7c;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff78;
  iVar5 = *(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1);
  ppvVar3 = &local_14;
  local_70 = in_ECX;
  local_14 = ExceptionList;
  local_78 = param_1;
  local_74 = param_2;
  while (ExceptionList = ppvVar3, iVar5 == 0) {
    iVar5 = FUN_00733980(param_1,uVar4);
    if (iVar5 < 1) goto joined_r0x00732381;
    FUN_00429630(1,iVar5);
    if (iVar5 == 0x3e) break;
    ppvVar3 = ExceptionList;
    iVar5 = *(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1);
  }
  if (2 < (uint)param_2[4]) {
    uVar4 = param_2[4] - 1;
    if ((uint)param_2[4] <= uVar4) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db7d("invalid string position");
    }
    uVar2 = param_2[5];
    puVar6 = param_2;
    if (0xf < uVar2) {
      puVar6 = (undefined4 *)*param_2;
    }
    if (*(char *)((int)puVar6 + uVar4) == '>') {
      uVar4 = param_2[4] - 2;
      if ((uint)param_2[4] <= uVar4) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid string position");
      }
      puVar6 = param_2;
      if (0xf < uVar2) {
        puVar6 = (undefined4 *)*param_2;
      }
      if (*(char *)((int)puVar6 + uVar4) == '/') goto LAB_00732616;
    }
    uVar4 = param_2[4] - 1;
    if ((uint)param_2[4] <= uVar4) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db7d("invalid string position");
    }
    puVar6 = param_2;
    if (0xf < uVar2) {
      puVar6 = (undefined4 *)*param_2;
    }
    if (*(char *)((int)puVar6 + uVar4) == '>') {
      do {
        while ((FUN_00731230(), *(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0 &&
               (iVar5 = FUN_00733b00(param_1), iVar5 != 0x3c))) {
          FUN_0072dcd0(appuStack_68);
          uStack_c = 0;
          FUN_00733180(param_1,param_2);
          uStack_c = 0xffffffff;
          appuStack_68[0] = TiXmlText::vftable;
          FUN_0072e040();
        }
        if (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) != 0) break;
        iStack_6c = param_2[4];
        cStack_7a = '\0';
        cStack_79 = '\0';
        while( true ) {
          if (*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) != 0) goto LAB_00732616;
          uVar4 = FUN_00733b00(param_1);
          puVar6 = local_74;
          if ((int)uVar4 < 1) goto LAB_007325fc;
          if (uVar4 == 0x3e) break;
          FUN_00429630(1,uVar4);
          FUN_00733980(local_78);
          if ((uVar4 == 0x5b) && (uVar2 = puVar6[4], 8 < uVar2)) {
            pbVar9 = &DAT_00c44d14;
            iVar5 = FUN_00403030();
            pbVar7 = (byte *)(iVar5 + -9 + uVar2);
            do {
              bVar1 = *pbVar7;
              bVar10 = bVar1 < *pbVar9;
              if (bVar1 != *pbVar9) {
LAB_00732534:
                iVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
                goto LAB_00732539;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar7[1];
              bVar10 = bVar1 < pbVar9[1];
              if (bVar1 != pbVar9[1]) goto LAB_00732534;
              pbVar7 = pbVar7 + 2;
              pbVar9 = pbVar9 + 2;
            } while (bVar1 != 0);
            iVar5 = 0;
LAB_00732539:
            if (iVar5 == 0) break;
          }
          param_1 = local_78;
          if ((((cStack_79 == '\0') && (uVar4 != 0x3c)) &&
              ((0xff < (int)uVar4 ||
               (((iVar5 = _isspace(uVar4 & 0xff), param_1 = local_78, iVar5 == 0 &&
                 ((char)uVar4 != '\n')) && ((char)uVar4 != '\r')))))) &&
             (cStack_79 = '\x01', param_1 = local_78, uVar4 == 0x2f)) {
            cStack_7a = '\x01';
          }
        }
        param_2 = local_74;
        if (cStack_7a != '\0') {
          if (*(int *)(*(int *)(*local_78 + 4) + 0xc + (int)local_78) == 0) {
            iVar5 = FUN_00733980(local_78);
            if (iVar5 < 1) {
LAB_007325fc:
              iVar5 = FUN_0072d980();
LAB_007323a9:
              if (iVar5 != 0) {
                FUN_00732010(0xe,0,0,0);
              }
            }
            else {
              FUN_00429630(1,iVar5);
            }
          }
          break;
        }
        iVar5 = FUN_00403030();
        piVar8 = (int *)FUN_007320a0(local_70,iVar5 + iStack_6c,0);
        if (piVar8 == (int *)0x0) break;
        (**(code **)(*piVar8 + 0x44))(local_78,param_2);
        (**(code **)*piVar8)(1);
        param_1 = local_78;
      } while( true );
    }
  }
LAB_00732616:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_7c);
  return;
joined_r0x00732381:
  if (local_70 == (int *)0x0) goto LAB_00732616;
  iVar5 = (**(code **)(*local_70 + 0x10))();
  if (iVar5 != 0) {
    iVar5 = (**(code **)(*local_70 + 0x10))();
    goto LAB_007323a9;
  }
  local_70 = (int *)local_70[4];
  goto joined_r0x00732381;
}

