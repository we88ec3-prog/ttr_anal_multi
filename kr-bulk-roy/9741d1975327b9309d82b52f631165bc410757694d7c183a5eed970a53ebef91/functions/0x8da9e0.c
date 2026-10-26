
int FUN_008da9e0(undefined4 param_1,int *param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  short sVar3;
  char cVar4;
  uint uVar5;
  undefined2 *puVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int *local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_8 = FUN_008d8190();
  if (local_8 == 0) {
    cVar4 = FUN_008d81c0();
    if (cVar4 == '\0') {
      return 2;
    }
    local_8 = FUN_008d81f0();
    if ((local_8 == 0) && (*param_2 = local_c, -1 < param_3)) {
      if (local_c <= param_3) {
        return 6;
      }
      local_8 = FUN_008d9dc0(param_1,param_2[0x33] != 0);
      if ((local_8 == 0) && (local_8 = FUN_008d87f0(param_1,param_2[0x47]), local_8 == 0)) {
        param_2[1] = param_3;
        param_2[2] = param_2[2] | 1;
        param_2[4] = param_2[0x66] + 1;
        uVar1 = param_2[0x66];
        uVar5 = 0;
        if (uVar1 != 0) {
          piVar8 = (int *)(param_2[0x68] + 0xc);
          do {
            if (*piVar8 != 0) break;
            uVar5 = uVar5 + 1;
            piVar8 = piVar8 + 4;
          } while (uVar5 < uVar1);
        }
        if (uVar5 == uVar1) {
          if (param_2[0x5f] == 0) {
            return 3;
          }
          param_2[2] = 0;
        }
        if ((*(byte *)(param_2 + 0x51) & 4) == 0) {
          param_2[2] = param_2[2] | 4;
        }
        if ((*(byte *)(param_2 + 0x51) & 1) == 0) {
          param_2[2] = param_2[2] | 0x10;
        }
        else {
          param_2[2] = param_2[2] | 0x20;
        }
        if (param_2[0x5f] != 0) {
          param_2[2] = param_2[2] | 2;
        }
        if (param_2[0x69] != 0) {
          param_2[2] = param_2[2] | 0x40;
        }
        param_2[5] = param_2[0x5d];
        if (param_2[0x5d] == 0) {
          param_2[5] = param_2[0x5c];
        }
        param_2[6] = param_2[0x5e];
        param_2[7] = 0;
        param_2[8] = 0;
        param_2[0xd] = param_2[0x4d];
        param_2[0xe] = param_2[0x4e];
        param_2[0xf] = param_2[0x4f];
        param_2[0x10] = param_2[0x50];
        *(ushort *)(param_2 + 0x11) = *(ushort *)(param_2 + 0x4b);
        *(short *)((int)param_2 + 0x46) = (short)param_2[0x50];
        *(short *)(param_2 + 0x12) = (short)param_2[0x4e];
        sVar3 = (short)(((uint)*(ushort *)(param_2 + 0x4b) * 0xc) / 10);
        *(short *)((int)param_2 + 0x4a) = sVar3;
        if ((int)sVar3 < (int)*(short *)((int)param_2 + 0x46) - (int)(short)param_2[0x12]) {
          *(short *)((int)param_2 + 0x4a) = *(short *)((int)param_2 + 0x46) - (short)param_2[0x12];
        }
        iVar7 = param_2[0x5f];
        if (iVar7 != 0) {
          puVar6 = (undefined2 *)
                   FUN_008bc7d0(*(undefined4 *)(param_2[0x1a] + 0x1c),0x10,0,iVar7,0,&local_8);
          param_2[8] = (int)puVar6;
          if (local_8 != 0) {
            return local_8;
          }
          piVar8 = (int *)param_2[0x61];
          for (iVar9 = iVar7; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar6 = (short)piVar8[1];
            puVar6[1] = (short)*piVar8;
            *(int *)(puVar6 + 2) = piVar8[1] << 6;
            *(int *)(puVar6 + 4) = *piVar8 << 6;
            *(int *)(puVar6 + 6) = piVar8[1] << 6;
            puVar6 = puVar6 + 8;
            piVar8 = piVar8 + 9;
          }
          param_2[7] = iVar7;
        }
        if ((*(byte *)(param_2 + 0x51) & 4) == 0) {
          *(short *)(param_2 + 0x13) = (short)param_2[0x52];
        }
        else {
          iVar7 = param_2[0x66];
          iVar9 = 0;
          if (iVar7 != 0) {
            piVar8 = (int *)(param_2[0x68] + 4);
            do {
              if (iVar9 < *piVar8) {
                iVar9 = *piVar8;
              }
              piVar8 = piVar8 + 4;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
          *(short *)(param_2 + 0x13) = (short)iVar9;
        }
        *(undefined2 *)((int)param_2 + 0x4e) = *(undefined2 *)((int)param_2 + 0x4a);
        lVar2 = (longlong)(int)(uint)*(ushort *)(param_2 + 0x11) * -0x66666667;
        *(short *)(param_2 + 0x14) = (short)(int)(lVar2 >> 0x22) - (short)(lVar2 >> 0x3f);
        *(ushort *)((int)param_2 + 0x52) = *(ushort *)(param_2 + 0x11) / 0x1e;
        local_18 = param_2;
        local_10 = 0x10003;
        local_14 = 0x756e6963;
        local_8 = FUN_008bcc30(&DAT_00be87ec,0,&local_18,0);
        if (param_2[0x69] != 0) {
          param_2[2] = param_2[2] | 0x40;
        }
      }
    }
  }
  return local_8;
}

