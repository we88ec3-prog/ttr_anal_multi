
undefined1 FUN_00546ef0(ushort param_1,int *param_2,int param_3)

{
  float fVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  undefined1 local_3d;
  int local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  float local_20;
  float local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093668e;
  local_14 = ExceptionList;
  if (param_2 == (int *)0x0) {
    return 0;
  }
  local_28 = param_2[0x38];
  iVar5 = param_2[0x39];
  local_3d = 0;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffb0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  local_38 = (float)(uint)param_1;
  FUN_0082ef00(&local_38);
  if (local_3c == DAT_00fab13c) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(local_3c + 0x10);
  }
  local_2c = *(float *)(iVar4 + 0xa4);
  local_34 = (float)param_2[0x29];
  fVar1 = *(float *)(iVar4 + 0xa0) - (float)param_2[0x28];
  local_38 = local_2c - local_34;
  local_30 = fVar1 * fVar1 + local_38 * local_38;
  local_20 = fVar1;
  local_1c = local_38;
  fVar6 = (float10)FUN_008ff870();
  local_30 = (float)fVar6;
  if (local_30 <= 10.0) {
    *(ushort *)(param_3 + 2) = *(ushort *)(param_3 + 2) & 0x7fff;
  }
  else {
    *(ushort *)(param_3 + 2) = *(ushort *)(param_3 + 2) | 0x8000;
    fVar6 = (float10)FUN_008fedca();
    local_30 = (float)fVar6 + 1.5707964;
    uVar2 = FUN_004bb450(local_30);
    *(undefined1 *)(param_3 + 4) = uVar2;
    local_1c = local_38;
    local_30 = fVar1 * fVar1 + local_38 * local_38;
    local_20 = fVar1;
    fVar6 = (float10)FUN_008ff870();
    local_30 = (float)fVar6;
    if (70.0 < local_30) {
      *(ushort *)(param_3 + 2) = *(ushort *)(param_3 + 2) | 2;
      local_3d = 1;
    }
  }
  if ((param_2[0x56] == 0) || (*(int *)(param_2[0x56] + 0x2c) == 0)) {
LAB_005470e3:
    *(ushort *)(param_3 + 2) = *(ushort *)(param_3 + 2) & 0x8000;
  }
  else {
    iVar4 = FUN_004c9ed0();
    if (iVar4 != 0) goto LAB_005470e3;
  }
  uVar3 = *(ushort *)(param_3 + 2) & 0x7fff;
  if (uVar3 != 0) {
    *(ushort *)(param_3 + 2) = uVar3;
  }
  if ((param_2[0x56] != 0) && (*(int *)(param_2[0x56] + 0x30) != 0)) {
    iVar4 = FUN_004c9ed0();
    if (iVar4 == 0) {
      if ((*(ushort *)(param_3 + 2) & 0x8000) == 0) {
        *(ushort *)(param_3 + 2) = *(ushort *)(param_3 + 2) & 0x7fff;
      }
      else {
        if (*(char *)(param_3 + 4) != (char)iVar5) {
          (**(code **)(*param_2 + 0x58))(*(char *)(param_3 + 4));
          local_3d = 1;
        }
        if (param_2[0x56] == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(param_2[0x56] + 0x28);
        }
        *(ushort *)(param_3 + 2) = *(ushort *)(param_3 + 2) & 0x7fff | (ushort)(iVar5 << 0xf);
      }
      goto LAB_00547178;
    }
  }
  *(ushort *)(param_3 + 2) = *(ushort *)(param_3 + 2) & 0x7fff;
LAB_00547178:
  if (((*(ushort *)(param_3 + 2) ^ local_28._2_2_) & 0x8000) != 0) {
    local_3d = 1;
  }
  ExceptionList = local_14;
  return local_3d;
}

