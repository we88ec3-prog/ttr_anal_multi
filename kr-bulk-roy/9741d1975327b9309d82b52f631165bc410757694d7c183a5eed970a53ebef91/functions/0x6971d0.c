
void FUN_006971d0(ushort *****param_1)

{
  ushort uVar1;
  ushort ****ppppuVar2;
  int iVar3;
  uint uVar4;
  ushort *****pppppuVar5;
  int iVar6;
  ushort *****pppppuVar7;
  uint uVar8;
  char unaff_BL;
  int *piVar9;
  bool bVar10;
  uint local_94;
  ushort ****local_90;
  undefined1 local_8c [16];
  uint uStack_7c;
  undefined1 local_54 [52];
  uint uStack_20;
  uint local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00942a4d;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_94;
  ExceptionList = &local_14;
  local_90 = (ushort ****)param_1;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 0;
    FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xffffff60);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  iVar6 = DAT_00fb7258;
  local_c = 0xffffffff;
  if (DAT_00fb7258 == 0) {
    (*(code *)(*param_1)[0x25])(0);
  }
  else {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    iVar3 = FUN_00539aa0(DAT_00f93930);
    if (iVar3 == 0) {
      (*(code *)(*param_1)[0x25])(0);
    }
    else {
      if ((*(char *)(iVar3 + 6) != '\0') ||
         (local_94 = local_94 & 0xffffff00, *(char *)(iVar3 + 8) != '\0')) {
        local_94 = CONCAT31(local_94._1_3_,1);
      }
      FUN_00757200(local_8c);
      local_c = 2;
      if (*(char *)(iVar3 + 6) == '\0') {
        FUN_0041f460(&DAT_00c392f4);
        local_c._0_1_ = 4;
        FUN_00405300(local_8c);
        local_c = CONCAT31(local_c._1_3_,2);
        FUN_00757640(local_54);
      }
      else {
        FUN_0041f460(&DAT_00c392ec);
        local_c._0_1_ = 3;
        FUN_00405300(local_8c);
        local_c = CONCAT31(local_c._1_3_,2);
        FUN_00757640(local_54);
        uVar4 = FUN_00539a70();
        if (uVar4 == 1) {
LAB_0069732c:
          local_94 = local_94 & 0xffffff00;
        }
        else {
          uVar8 = 0;
          if (uVar4 != 0) {
            piVar9 = *(int **)(iVar6 + 0x28);
            iVar6 = *(int *)(iVar6 + 0x2c) - (int)piVar9;
            do {
              if ((((uVar8 < (uint)(iVar6 >> 2)) && (iVar3 = *piVar9, *(char *)(iVar3 + 10) != '\0')
                   ) && (iVar3 != 0)) &&
                 ((*(char *)(iVar3 + 6) == '\0' && (*(char *)(iVar3 + 8) == '\0'))))
              goto LAB_0069732c;
              uVar8 = uVar8 + 1;
              piVar9 = piVar9 + 1;
            } while (uVar8 < uVar4);
          }
        }
      }
      ppppuVar2 = local_90;
      (*(code *)(*local_90)[0x25])(local_94);
      if (unaff_BL != '\0') {
        pppppuVar7 = (ushort *****)local_90;
        if (uStack_7c < 8) {
          pppppuVar7 = &local_90;
        }
        pppppuVar5 = (ushort *****)(ppppuVar2 + 0x3a);
        if ((ushort ****)0x7 < ppppuVar2[0x3f]) {
          pppppuVar5 = (ushort *****)*pppppuVar5;
        }
        do {
          uVar1 = *(ushort *)pppppuVar5;
          bVar10 = uVar1 < *(ushort *)pppppuVar7;
          if (uVar1 != *(ushort *)pppppuVar7) {
LAB_00697406:
            iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
            goto LAB_0069740b;
          }
          if (uVar1 == 0) break;
          uVar1 = *(ushort *)((int)pppppuVar5 + 2);
          bVar10 = uVar1 < *(ushort *)((int)pppppuVar7 + 2);
          if (uVar1 != *(ushort *)((int)pppppuVar7 + 2)) goto LAB_00697406;
          pppppuVar5 = pppppuVar5 + 1;
          pppppuVar7 = pppppuVar7 + 1;
        } while (uVar1 != 0);
        iVar6 = 0;
LAB_0069740b:
        if (iVar6 != 0) {
          FUN_00405300(ppppuVar2 + 0x3a);
          (*(code *)(*ppppuVar2)[0x32])();
        }
      }
      puStack_10 = (undefined1 *)0xffffffff;
      FUN_00757640(&local_90);
    }
  }
  ExceptionList = pvStack_18;
  __security_check_cookie(uStack_20 ^ (uint)&stack0xffffff68);
  return;
}

