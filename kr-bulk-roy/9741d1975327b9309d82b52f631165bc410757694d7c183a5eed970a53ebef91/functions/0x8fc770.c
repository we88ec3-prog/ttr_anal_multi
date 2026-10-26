
uint FUN_008fc770(int *param_1,undefined1 *param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  piVar1 = param_1;
  local_14 = param_1[0x12];
  local_c = param_1[0x11];
  local_8 = param_1[0x10];
  uVar4 = 0;
  local_10 = 0;
  if (param_3 != 0) {
    iVar3 = *param_1;
    if (iVar3 == 0) {
      iVar3 = FUN_008b97e0(param_1[0x29],2);
      if ((iVar3 == 0) && (iVar3 = FUN_008b98e0(piVar1[0x29],(int)&param_1 + 3,1), iVar3 == 1)) {
        uVar2 = (uint)param_1 >> 0x18 & 0x1f;
        iVar3 = 1 << (sbyte)uVar2;
        piVar1[10] = uVar2;
        piVar1[0xb] = (uint)param_1 >> 0x18 & 0x80;
        piVar1[0xc] = iVar3 + -0x100;
        uVar4 = local_10;
        if (uVar2 < 0x11) {
          piVar1[0xd] = 9;
          local_14 = 0;
          piVar1[0xe] = (uint)(((uint)param_1 & 0x80000000) != 0);
          if (uVar2 < 10) {
            iVar3 = iVar3 + -0xff;
          }
          else {
            iVar3 = 0x100;
          }
          piVar1[0xf] = iVar3;
          uVar2 = FUN_008fc4d0();
          if (uVar2 < 0x100) {
            if (param_2 != (undefined1 *)0x0) {
              *param_2 = (char)uVar2;
            }
            uVar4 = 1;
            local_c = uVar2;
            local_8 = uVar2;
            if (1 < param_3) {
              *piVar1 = 1;
              goto LAB_008fc871;
            }
            goto LAB_008fc9df;
          }
        }
      }
LAB_008fc9d8:
      *piVar1 = 3;
    }
    else {
      if (iVar3 == 1) goto LAB_008fc871;
      if (iVar3 == 2) {
        do {
          iVar3 = piVar1[0x17];
          while (iVar3 != 0) {
            piVar1[0x17] = piVar1[0x17] + -1;
            if (param_2 != (undefined1 *)0x0) {
              param_2[uVar4] = *(undefined1 *)(piVar1[0x17] + piVar1[0x16]);
            }
            uVar4 = uVar4 + 1;
            if (uVar4 == param_3) goto LAB_008fc9df;
            iVar3 = piVar1[0x17];
          }
          if ((uint)piVar1[0xe] < (uint)piVar1[0xc]) {
            if (((uint)piVar1[0x15] <= (uint)piVar1[0xe]) && (iVar3 = FUN_008fc610(), iVar3 < 0))
            goto LAB_008fc9d8;
            *(undefined2 *)(piVar1[0x13] + piVar1[0xe] * 2) = (undefined2)local_8;
            *(undefined1 *)(piVar1[0x14] + piVar1[0xe]) = (undefined1)local_c;
            piVar1[0xe] = piVar1[0xe] + 1;
          }
          local_8 = local_14;
          *piVar1 = 1;
LAB_008fc871:
          while( true ) {
            uVar2 = FUN_008fc4d0();
            if ((int)uVar2 < 0) goto LAB_008fc9d8;
            if ((uVar2 != 0x100) || (piVar1[0xb] == 0)) break;
            piVar1[0xe] = 0;
            *(undefined1 *)(piVar1 + 8) = 1;
            local_8 = 0;
            local_c = 0;
          }
          local_14 = uVar2;
          if (0xff < uVar2) {
            if ((uint)piVar1[0xe] <= uVar2 - 0x100) {
              if (((uint)piVar1[0xe] < uVar2 - 0x100) ||
                 (((uint)piVar1[0x18] <= (uint)piVar1[0x17] && (iVar3 = FUN_008fc5a0(), iVar3 < 0)))
                 ) goto LAB_008fc9d8;
              *(undefined1 *)(piVar1[0x16] + piVar1[0x17]) = (undefined1)local_c;
              piVar1[0x17] = piVar1[0x17] + 1;
              uVar2 = local_8;
            }
            for (; 0xff < uVar2; uVar2 = (uint)*(ushort *)(piVar1[0x13] + -0x200 + uVar2 * 2)) {
              if ((piVar1[0x13] == 0) ||
                 (((uint)piVar1[0x18] <= (uint)piVar1[0x17] && (iVar3 = FUN_008fc5a0(), iVar3 < 0)))
                 ) goto LAB_008fc9d8;
              *(undefined1 *)(piVar1[0x16] + piVar1[0x17]) =
                   *(undefined1 *)(piVar1[0x14] + -0x100 + uVar2);
              piVar1[0x17] = piVar1[0x17] + 1;
            }
          }
          local_c = uVar2;
          if (((uint)piVar1[0x18] <= (uint)piVar1[0x17]) && (iVar3 = FUN_008fc5a0(), iVar3 < 0))
          goto LAB_008fc9d8;
          *(char *)(piVar1[0x16] + piVar1[0x17]) = (char)uVar2;
          piVar1[0x17] = piVar1[0x17] + 1;
          *piVar1 = 2;
        } while( true );
      }
    }
  }
LAB_008fc9df:
  piVar1[0x11] = local_c;
  piVar1[0x10] = local_8;
  piVar1[0x12] = local_14;
  return uVar4;
}

