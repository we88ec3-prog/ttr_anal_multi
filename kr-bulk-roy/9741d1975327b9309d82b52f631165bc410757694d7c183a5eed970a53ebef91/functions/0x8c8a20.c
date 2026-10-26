
int FUN_008c8a20(int param_1,uint param_2,ushort *param_3)

{
  char cVar1;
  undefined4 uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  if (*(uint *)(param_1 + 0x2e0) <= param_2) {
    return 6;
  }
  uVar5 = *(uint *)(param_1 + 0x2dc);
  if (uVar5 != 0) {
    if (uVar5 < 3) {
      iVar4 = *(int *)(param_1 + 0x2d4) + 8 + param_2 * 0x30;
      *param_3 = (ushort)*(byte *)(*(int *)(param_1 + 0x2d4) + 0x34 + param_2 * 0x30);
      param_3[1] = (ushort)*(byte *)(iVar4 + 0x2d);
      *(int *)(param_3 + 6) = (int)*(char *)(iVar4 + 0x10) << 6;
      cVar1 = *(char *)(iVar4 + 0x11);
      *(int *)(param_3 + 8) = cVar1 * 0x40;
      *(int *)(param_3 + 10) = *(int *)(param_3 + 6) + cVar1 * -0x40;
      *(uint *)(param_3 + 0xc) =
           ((int)*(char *)(iVar4 + 0x17) + (int)*(char *)(iVar4 + 0x16) +
           (uint)*(byte *)(iVar4 + 0x12)) * 0x40;
      return 0;
    }
    if (uVar5 == 3) {
      iVar6 = *(int *)(param_1 + 0x2d4);
      uVar2 = *(undefined4 *)(param_1 + 0x68);
      iVar4 = iVar6 + 0xc + param_2 * 4;
      iVar6 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar6 + 8 + param_2 * 4),
                                         *(undefined1 *)(iVar6 + 9 + param_2 * 4)),
                                *(undefined1 *)(iVar4 + -2)),*(undefined1 *)(iVar4 + -1));
      iVar4 = (**(code **)(param_1 + 0x1fc))(param_1,0x73626978,uVar2,&param_2);
      if (iVar4 == 0) {
        if (param_2 < iVar6 + 4U) {
          iVar4 = 3;
        }
        else {
          iVar4 = FUN_008b9850(uVar2);
          iVar4 = FUN_008b97e0(uVar2,iVar4 + iVar6);
          if (iVar4 == 0) {
            iVar4 = FUN_008babe0(uVar2,4);
            if (iVar4 == 0) {
              uVar3 = FUN_008b9960(uVar2);
              uVar7 = (uint)uVar3;
              FUN_008b9960(uVar2);
              FUN_008baca0(uVar2);
              uVar5 = (uint)*(ushort *)(param_1 + 0xb2);
              *param_3 = uVar3;
              param_3[1] = uVar3;
              *(uint *)(param_3 + 6) = ((int)*(short *)(param_1 + 0xdc) * uVar7 * 0x40) / uVar5;
              *(uint *)(param_3 + 8) = ((int)*(short *)(param_1 + 0xde) * uVar7 * 0x40) / uVar5;
              *(uint *)(param_3 + 10) =
                   ((((int)*(short *)(param_1 + 0xe0) - (int)*(short *)(param_1 + 0xde)) +
                    (int)*(short *)(param_1 + 0xdc)) * uVar7 * 0x40) / uVar5;
              *(uint *)(param_3 + 0xc) = (*(ushort *)(param_1 + 0xe2) * uVar7 * 0x40) / uVar5;
              return 0;
            }
          }
        }
      }
      return iVar4;
    }
  }
  return 2;
}

