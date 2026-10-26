
void FUN_008f7630(int *param_1,int param_2,undefined4 param_3,uint param_4,int param_5)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined2 local_74;
  undefined2 uStack_72;
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  int local_5c;
  int *local_58;
  uint local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int *local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  int *local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_40 = (int *)param_1[0x21];
  local_50 = param_2;
  iVar1 = *(int *)(*param_1 + 0x54);
  local_58 = *(int **)(iVar1 + 0x9c);
  iVar7 = param_1[2];
  iVar6 = FUN_008bb2e0(*param_1,param_3,param_4 | 0x2000);
  if (iVar6 == 0) {
    iVar6 = local_58[2];
    *(char *)(param_1 + 0x22) = (char)iVar6;
    if ((char)iVar6 != '\0') {
      param_1[0x23] = local_58[3];
      param_1[0x24] = local_58[4];
      param_1[0x25] = local_58[5];
      param_1[0x26] = local_58[6];
      param_1[0x27] = local_58[7];
      local_14 = param_1[0x24];
      local_18 = param_1[0x23];
      param_1[0x28] = local_58[8];
      local_10 = param_1[0x25];
      local_c = param_1[0x26];
      FUN_008b7fd0(&local_18);
      FUN_008b9510(param_1 + 0x27,&local_18);
    }
    if (*(int *)(iVar1 + 0x48) == 0x636f6d70) {
      local_34 = *(uint *)(iVar1 + 0x80);
      local_4c = (int)*(short *)(iVar7 + 0x16);
      local_44 = FUN_008bcb10(iVar7,local_34);
      if (local_44 != 0) goto LAB_008f7efe;
      FID_conflict__memcpy(*(void **)(iVar7 + 0x58),*(void **)(iVar1 + 0x84),local_34 << 5);
      *(uint *)(iVar7 + 0x54) = local_34;
      local_1c = 0;
      if (local_34 != 0) {
        local_48 = *(int *)(iVar7 + 0x30) << 5;
        do {
          local_5c = param_1[0x2a];
          local_60 = param_1[0x29];
          local_c = param_1[0x2c];
          local_10 = param_1[0x2b];
          local_38 = (uint)*(short *)(iVar7 + 0x16);
          local_44 = FUN_008f7630(param_1,local_50,
                                  *(undefined4 *)(*(int *)(iVar7 + 0x34) + local_48),param_4,
                                  param_5 + 1);
          if (local_44 != 0) goto LAB_008f7efe;
          local_24 = *(int *)(iVar7 + 0x34) + local_48;
          if ((*(ushort *)(local_24 + 4) & 0x200) == 0) {
            param_1[0x29] = local_60;
            param_1[0x2a] = local_5c;
            param_1[0x2b] = local_10;
            param_1[0x2c] = local_c;
          }
          local_54 = (int)*(short *)(iVar7 + 0x16) - local_38;
          if ((*(byte *)(local_24 + 4) & 200) != 0) {
            local_3c = *(int *)(iVar7 + 0x18) + local_38 * 8;
            local_20 = (int *)(local_3c + local_54 * 8);
            if (local_3c < local_20) {
              do {
                FUN_008b9510(local_3c,local_24 + 0x10);
                local_3c = local_3c + 8;
              } while (local_3c < local_20);
            }
          }
          if ((*(byte *)(local_24 + 4) & 2) == 0) {
            local_20 = *(int **)(local_24 + 0xc);
            local_24 = local_4c + *(int *)(local_24 + 8);
            if ((local_38 <= local_24) || (local_54 <= local_20)) {
              __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
              return;
            }
            iVar6 = *(int *)(iVar7 + 0x18);
            local_20 = (int *)(iVar6 + ((int)local_20 + local_38 + local_4c) * 8);
            uVar8 = *(int *)(iVar6 + local_24 * 8) - *local_20;
            local_24 = *(int *)(iVar6 + 4 + local_24 * 8) - local_20[1];
          }
          else {
            lVar3 = (longlong)*(int *)(local_24 + 8) * (longlong)param_1[4];
            lVar3 = lVar3 + (ulonglong)((int)(lVar3 >> 0x3f) + 0x8000);
            local_28 = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
            local_3c = param_1[5] + local_28;
            local_20 = (int *)param_1[6];
            lVar3 = (longlong)*(int *)(local_24 + 0xc) * (longlong)(int)local_20;
            lVar3 = lVar3 + (ulonglong)((int)(lVar3 >> 0x3f) + 0x8000);
            local_30 = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
            uVar8 = local_3c + 0x20 & 0xffffffc0;
            local_24 = param_1[7] + 0x20 + local_30 & 0xffffffc0;
          }
          local_6c = *(undefined4 *)(iVar7 + 0x1c);
          local_68 = *(undefined4 *)(iVar7 + 0x20);
          local_64 = *(undefined4 *)(iVar7 + 0x24);
          local_70 = *(int *)(iVar7 + 0x18) + local_38 * 8;
          _local_74 = CONCAT22((undefined2)local_54,(short)*(undefined4 *)(iVar7 + 0x14));
          FUN_008b94d0(&local_74,uVar8,local_24);
          local_48 = local_48 + 0x20;
          local_1c = local_1c + 1;
        } while (local_1c < local_34);
      }
    }
    else if (*(int *)(iVar1 + 0x48) == 0x6f75746c) {
      if ((char)param_1[0x22] != '\0') {
        FUN_008b94d0(iVar1 + 0x6c,param_1[0x27],param_1[0x28]);
      }
      local_1c = (int)*(short *)(iVar1 + 0x6e) + 4;
      if (((local_1c == 0) ||
          ((uint)(*(short *)(iVar7 + 0x16) + 4 +
                 (int)*(short *)(iVar7 + 0x3a) + (int)*(short *)(iVar1 + 0x6e)) <=
           *(uint *)(iVar7 + 4))) &&
         ((*(short *)(iVar1 + 0x6c) == 0 ||
          ((uint)((int)*(short *)(iVar7 + 0x38) + (int)*(short *)(iVar7 + 0x14) +
                 (int)*(short *)(iVar1 + 0x6c)) <= *(uint *)(iVar7 + 8))))) {
        local_44 = 0;
      }
      else {
        local_44 = FUN_008bc9a0(iVar7,local_1c,(int)*(short *)(iVar1 + 0x6c));
        if (local_44 != 0) goto LAB_008f7efe;
      }
      FID_conflict__memcpy
                (*(void **)(iVar7 + 0x3c),*(void **)(iVar1 + 0x70),*(short *)(iVar1 + 0x6e) * 8);
      FID_conflict__memcpy
                (*(void **)(iVar7 + 0x44),*(void **)(iVar1 + 0x78),*(short *)(iVar1 + 0x6c) * 2);
      FID_conflict__memcpy
                (*(void **)(iVar7 + 0x40),*(void **)(iVar1 + 0x74),(int)*(short *)(iVar1 + 0x6e));
      *(undefined2 *)(iVar7 + 0x3a) = *(undefined2 *)(iVar1 + 0x6e);
      *(undefined2 *)(iVar7 + 0x38) = *(undefined2 *)(iVar1 + 0x6c);
      param_1[0x29] = param_1[5];
      param_1[0x2a] = param_1[7];
      local_1c = param_1[4];
      local_30 = *(int *)(iVar1 + 0x28);
      lVar3 = (longlong)local_30 * (longlong)(int)local_1c +
              (ulonglong)((int)((longlong)local_30 * (longlong)(int)local_1c >> 0x3f) + 0x8000);
      local_34 = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
      param_1[0x2b] = param_1[5] + local_34;
      param_1[0x2c] = param_1[7];
      if (*(short *)(iVar1 + 0x6e) != 0) {
        if (*(code **)((&PTR_DAT_00bebb70)[*(int *)(*local_40 + 4)] + 0x18) != (code *)0x0) {
          (**(code **)((&PTR_DAT_00bebb70)[*(int *)(*local_40 + 4)] + 0x18))
                    (param_1 + 3,iVar7 + 0x38,local_40);
        }
        if (*(int *)(local_50 + 0x14) == 1) {
          iVar6 = param_1[0x29];
          iVar2 = param_1[0x2b];
          param_1[0x29] = param_1[0x1f] + 0x20 + iVar6 & 0xffffffc0;
          param_1[0x2b] = param_1[0x20] + 0x20 + iVar2 & 0xffffffc0;
          *(int *)(iVar1 + 0x90) = param_1[0x29] - iVar6;
          *(int *)(iVar1 + 0x94) = param_1[0x2b] - iVar2;
          FUN_008b8370(iVar7);
        }
        else {
          iVar6 = param_1[0x13];
          local_34 = iVar6 + -0x30 + param_1[0x11] * 0x30;
          if ((param_1[0x11] < 2) || ((*(byte *)(param_1 + 0x1c) & 4) != 0)) {
            iVar6 = param_1[0x29];
            local_1c = param_1[0x2b];
            uVar8 = iVar6 + 0x20U & 0xffffffc0;
            param_1[0x29] = uVar8;
            param_1[0x2b] = local_1c + 0x20 & 0xffffffc0;
            *(uint *)(iVar1 + 0x90) = uVar8 - iVar6;
            *(uint *)(iVar1 + 0x94) = param_1[0x2b] - local_1c;
            FUN_008b8370(iVar7);
          }
          else {
            local_4c = param_1[0x2b] - *(int *)(local_34 + 4);
            local_30 = *(int *)(iVar6 + 4);
            local_1c = *(uint *)(iVar6 + 8);
            local_38 = local_1c - local_30;
            iVar6 = *(int *)(local_34 + 8) + local_4c;
            if (local_30 < 0x18) {
              local_38 = local_38 - 8;
            }
            if (local_4c < 0x18) {
              iVar6 = iVar6 + 8;
            }
            uVar8 = local_38 + 0x20 & 0xffffffc0;
            local_28 = iVar6 + 0x20U & 0xffffffc0;
            param_1[0x29] = uVar8;
            param_1[0x2b] = local_28;
            if (((int)local_1c <= (int)uVar8) && (0 < local_30)) {
              param_1[0x29] = uVar8 - 0x40;
            }
            if (((int)local_28 <= *(int *)(local_34 + 8)) && (0 < local_4c)) {
              param_1[0x2b] = local_28 + 0x40;
            }
            *(uint *)(iVar1 + 0x90) = param_1[0x29] - local_38;
            *(int *)(iVar1 + 0x94) = param_1[0x2b] - iVar6;
            FUN_008b8370(iVar7);
          }
        }
      }
    }
    else {
      local_44 = 7;
    }
    if (param_5 == 0) {
      lVar3 = (longlong)(*(int *)(iVar1 + 0x2c) - *(int *)(iVar1 + 0x20)) * (longlong)local_40[2];
      lVar3 = lVar3 + (ulonglong)((int)(lVar3 >> 0x3f) + 0x8000);
      local_2c = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
      local_20 = (int *)local_40[3];
      lVar3 = (longlong)(*(int *)(iVar1 + 0x30) - *(int *)(iVar1 + 0x24)) * (longlong)(int)local_20;
      lVar3 = lVar3 + (ulonglong)((int)(lVar3 >> 0x3f) + 0x8000);
      local_28 = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
      local_1c = local_28;
      if ((char)param_1[0x22] != '\0') {
        FUN_008b9570(iVar7 + 0x14,param_1 + 0x23);
        FUN_008b9510(&local_2c,param_1 + 0x23);
      }
      if (param_1[0x29] != 0) {
        FUN_008b94d0(iVar7 + 0x14,-param_1[0x29],0);
      }
      FUN_008b9440(iVar7 + 0x14,&local_18);
      local_14 = local_14 & 0xffffffc0;
      local_10 = local_10 + 0x3f & 0xffffffc0;
      local_18 = local_18 & 0xffffffc0;
      local_c = local_c + 0x3f & 0xffffffc0;
      *(uint *)(iVar1 + 0x18) = local_10 - local_18;
      *(uint *)(iVar1 + 0x20) = local_18;
      *(uint *)(iVar1 + 0x24) = local_c;
      *(uint *)(iVar1 + 0x1c) = local_c - local_14;
      *(uint *)(iVar1 + 0x2c) = local_18 + local_2c & 0xffffffc0;
      *(uint *)(iVar1 + 0x30) = local_c + local_28 & 0xffffffc0;
      if ((*(int *)(local_50 + 0x14) == 1) ||
         (((*(byte *)(*(int *)(iVar1 + 4) + 8) & 4) == 0 &&
          ((cVar5 = FUN_008f40b0(), cVar5 == '\0' || ((char)local_40[8] == '\0')))))) {
        if (*(int *)(iVar1 + 0x28) != 0) {
          *(int *)(iVar1 + 0x28) = param_1[0x2b] - param_1[0x29];
        }
      }
      else {
        lVar3 = (longlong)*(int *)(iVar1 + 0x28) * (longlong)local_40[2];
        lVar3 = lVar3 + (ulonglong)((int)(lVar3 >> 0x3f) + 0x8000);
        *(uint *)(iVar1 + 0x28) = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
        *(undefined4 *)(iVar1 + 0x90) = 0;
        *(undefined4 *)(iVar1 + 0x94) = 0;
      }
      piVar4 = local_58;
      local_20 = (int *)local_40[3];
      local_30 = *(int *)(iVar1 + 0x34);
      lVar3 = (longlong)local_30 * (longlong)(int)local_20 +
              (ulonglong)((int)((longlong)local_30 * (longlong)(int)local_20 >> 0x3f) + 0x8000);
      local_1c = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
      *(uint *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + 0x20U & 0xffffffc0;
      *(uint *)(iVar1 + 0x34) = local_1c + 0x20 & 0xffffffc0;
      FUN_008b82d0(*local_58);
      iVar7 = FUN_008bcb70(*piVar4,iVar7);
      if (iVar7 == 0) {
        *(undefined2 *)(iVar1 + 0x6c) = *(undefined2 *)(*piVar4 + 0x14);
        *(undefined2 *)(iVar1 + 0x6e) = *(undefined2 *)(*piVar4 + 0x16);
        *(undefined4 *)(iVar1 + 0x70) = *(undefined4 *)(*piVar4 + 0x18);
        *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(*piVar4 + 0x1c);
        *(undefined4 *)(iVar1 + 0x78) = *(undefined4 *)(*piVar4 + 0x20);
        *(undefined4 *)(iVar1 + 0x48) = 0x6f75746c;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
LAB_008f7efe:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

