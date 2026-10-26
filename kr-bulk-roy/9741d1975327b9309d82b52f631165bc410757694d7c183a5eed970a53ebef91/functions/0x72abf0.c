
byte FUN_0072abf0(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  short sVar10;
  uint local_8;
  
  local_8 = 0;
LAB_0072ac01:
  do {
    uVar6 = param_1[0x1d];
    if (uVar6 < 0x106) {
      FUN_0072a540();
      uVar6 = param_1[0x1d];
      if ((uVar6 < 0x106) && (param_2 == 0)) {
        return 0;
      }
      if (uVar6 == 0) {
        if (param_1[0x1a] != 0) {
          bVar5 = *(byte *)(param_1[0x1b] + -1 + param_1[0xe]);
          *(undefined2 *)(param_1[0x5a9] + param_1[0x5a8] * 2) = 0;
          *(byte *)(param_1[0x5a6] + param_1[0x5a8]) = bVar5;
          param_1[0x5a8] = param_1[0x5a8] + 1;
          *(short *)(param_1 + bVar5 + 0x25) = (short)param_1[bVar5 + 0x25] + 1;
          param_1[0x1a] = 0;
        }
        if (param_1[0x17] < 0) {
          iVar7 = 0;
        }
        else {
          iVar7 = param_1[0xe] + param_1[0x17];
        }
        FUN_0072d0f0(iVar7,param_2 == 4);
        param_1[0x17] = param_1[0x1b];
        FUN_007299d0();
        if (*(int *)(*param_1 + 0x10) != 0) {
          return (param_2 == 4) * '\x02' + 1;
        }
        return (param_2 != 4) - 1U & 2;
      }
    }
    if (2 < uVar6) {
      uVar6 = (param_1[0x12] << ((byte)param_1[0x16] & 0x1f) ^
              (uint)*(byte *)(param_1[0xe] + 2 + param_1[0x1b])) & param_1[0x15];
      param_1[0x12] = uVar6;
      *(undefined2 *)(param_1[0x10] + (param_1[0xd] & param_1[0x1b]) * 2) =
           *(undefined2 *)(param_1[0x11] + uVar6 * 2);
      local_8 = (uint)*(ushort *)(param_1[0x10] + (param_1[0x1b] & param_1[0xd]) * 2);
      *(short *)(param_1[0x11] + param_1[0x12] * 2) = (short)param_1[0x1b];
    }
    uVar6 = param_1[0x18];
    param_1[0x19] = param_1[0x1c];
    param_1[0x1e] = uVar6;
    param_1[0x18] = 2;
    if (((local_8 != 0) && (uVar6 < (uint)param_1[0x20])) &&
       (param_1[0x1b] - local_8 <= param_1[0xb] - 0x106U)) {
      if (param_1[0x22] != 2) {
        if (param_1[0x22] == 3) {
          if (param_1[0x1b] - local_8 != 1) goto LAB_0072ace1;
          iVar7 = FUN_0072a4a0();
        }
        else {
          iVar7 = FUN_0072a340(local_8);
        }
        param_1[0x18] = iVar7;
      }
LAB_0072ace1:
      if (((uint)param_1[0x18] < 6) &&
         ((param_1[0x22] == 1 ||
          ((param_1[0x18] == 3 && (0x1000 < (uint)(param_1[0x1b] - param_1[0x1c]))))))) {
        param_1[0x18] = 2;
      }
    }
    if (((uint)param_1[0x1e] < 3) || ((uint)param_1[0x1e] < (uint)param_1[0x18])) {
      if (param_1[0x1a] == 0) {
        param_1[0x1b] = param_1[0x1b] + 1;
        param_1[0x1d] = param_1[0x1d] + -1;
        param_1[0x1a] = 1;
        goto LAB_0072ac01;
      }
      bVar5 = *(byte *)(param_1[0x1b] + -1 + param_1[0xe]);
      *(undefined2 *)(param_1[0x5a9] + param_1[0x5a8] * 2) = 0;
      *(byte *)(param_1[0x5a6] + param_1[0x5a8]) = bVar5;
      param_1[0x5a8] = param_1[0x5a8] + 1;
      *(short *)(param_1 + bVar5 + 0x25) = (short)param_1[bVar5 + 0x25] + 1;
      if (param_1[0x5a8] == param_1[0x5a7] + -1) {
        if (param_1[0x17] < 0) {
          iVar7 = 0;
        }
        else {
          iVar7 = param_1[0xe] + param_1[0x17];
        }
        FUN_0072d0f0(iVar7,0);
        iVar7 = *param_1;
        param_1[0x17] = param_1[0x1b];
        uVar6 = *(uint *)(*(int *)(iVar7 + 0x1c) + 0x14);
        if (*(uint *)(iVar7 + 0x10) < uVar6) {
          uVar6 = *(uint *)(iVar7 + 0x10);
        }
        if (uVar6 != 0) {
          FID_conflict__memcpy
                    (*(void **)(iVar7 + 0xc),*(void **)(*(int *)(iVar7 + 0x1c) + 0x10),uVar6);
          *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + uVar6;
          piVar1 = (int *)(*(int *)(iVar7 + 0x1c) + 0x10);
          *piVar1 = *piVar1 + uVar6;
          *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + uVar6;
          *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) - uVar6;
          piVar1 = (int *)(*(int *)(iVar7 + 0x1c) + 0x14);
          *piVar1 = *piVar1 - uVar6;
          iVar7 = *(int *)(iVar7 + 0x1c);
          if (*(int *)(iVar7 + 0x14) == 0) {
            *(undefined4 *)(iVar7 + 0x10) = *(undefined4 *)(iVar7 + 8);
          }
        }
      }
      param_1[0x1b] = param_1[0x1b] + 1;
      param_1[0x1d] = param_1[0x1d] + -1;
    }
    else {
      sVar10 = (short)param_1[0x1b] - (short)param_1[0x19];
      iVar7 = param_1[0x1b];
      iVar2 = param_1[0x1d];
      iVar4 = param_1[0x1e];
      *(short *)(param_1[0x5a9] + param_1[0x5a8] * 2) = sVar10 + -1;
      bVar5 = (char)iVar4 - 3;
      *(byte *)(param_1[0x5a6] + param_1[0x5a8]) = bVar5;
      param_1[0x5a8] = param_1[0x5a8] + 1;
      *(short *)(param_1 + (byte)(&DAT_00c089a0)[bVar5] + 0x126) =
           (short)param_1[(byte)(&DAT_00c089a0)[bVar5] + 0x126] + 1;
      uVar9 = sVar10 - 2;
      if (uVar9 < 0x100) {
        bVar5 = (&DAT_00c087a0)[uVar9];
      }
      else {
        bVar5 = (&DAT_00c088a0)[uVar9 >> 7];
      }
      *(short *)(param_1 + bVar5 + 0x262) = (short)param_1[bVar5 + 0x262] + 1;
      iVar4 = param_1[0x5a7];
      iVar3 = param_1[0x5a8];
      param_1[0x1d] = param_1[0x1d] + (1 - param_1[0x1e]);
      param_1[0x1e] = param_1[0x1e] + -2;
      do {
        param_1[0x1b] = param_1[0x1b] + 1;
        uVar6 = param_1[0x1b];
        if (uVar6 <= (uint)(iVar7 + -3 + iVar2)) {
          uVar8 = (param_1[0x12] << ((byte)param_1[0x16] & 0x1f) ^
                  (uint)*(byte *)(param_1[0xe] + 2 + uVar6)) & param_1[0x15];
          param_1[0x12] = uVar8;
          *(undefined2 *)(param_1[0x10] + (uVar6 & param_1[0xd]) * 2) =
               *(undefined2 *)(param_1[0x11] + uVar8 * 2);
          local_8 = (uint)*(ushort *)(param_1[0x10] + (param_1[0x1b] & param_1[0xd]) * 2);
          *(short *)(param_1[0x11] + param_1[0x12] * 2) = (short)param_1[0x1b];
        }
        piVar1 = param_1 + 0x1e;
        *piVar1 = *piVar1 + -1;
      } while (*piVar1 != 0);
      param_1[0x1b] = param_1[0x1b] + 1;
      param_1[0x1a] = 0;
      param_1[0x18] = 2;
      if (iVar3 != iVar4 + -1) goto LAB_0072ac01;
      if (param_1[0x17] < 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = param_1[0xe] + param_1[0x17];
      }
      FUN_0072d0f0(iVar7,0);
      iVar7 = *param_1;
      param_1[0x17] = param_1[0x1b];
      uVar6 = *(uint *)(*(int *)(iVar7 + 0x1c) + 0x14);
      if (*(uint *)(iVar7 + 0x10) < uVar6) {
        uVar6 = *(uint *)(iVar7 + 0x10);
      }
      if (uVar6 != 0) {
        FID_conflict__memcpy
                  (*(void **)(iVar7 + 0xc),*(void **)(*(int *)(iVar7 + 0x1c) + 0x10),uVar6);
        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + uVar6;
        piVar1 = (int *)(*(int *)(iVar7 + 0x1c) + 0x10);
        *piVar1 = *piVar1 + uVar6;
        *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + uVar6;
        *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) - uVar6;
        piVar1 = (int *)(*(int *)(iVar7 + 0x1c) + 0x14);
        *piVar1 = *piVar1 - uVar6;
        iVar7 = *(int *)(iVar7 + 0x1c);
        if (*(int *)(iVar7 + 0x14) == 0) {
          *(undefined4 *)(iVar7 + 0x10) = *(undefined4 *)(iVar7 + 8);
        }
      }
    }
    if (*(int *)(*param_1 + 0x10) == 0) {
      return 0;
    }
  } while( true );
}

