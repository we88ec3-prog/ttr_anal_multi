
int * FUN_007f89b0(int *param_1,int param_2,float param_3,float param_4,float param_5,int param_6,
                  int param_7,int param_8,int param_9,int param_10,int param_11)

{
  uint uVar1;
  int iVar2;
  uint in_ECX;
  undefined4 *puVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009053d8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[1] = 0;
  param_1[7] = 0xf;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x31] = 0;
  param_1[0x33] = 0;
  param_1[0xf] = 0x3f800000;
  param_1[0x35] = 0;
  local_8 = 0;
  *param_1 = (int)IS3D::CSnow::vftable;
  param_1[0x39] = 0x7f7fffff;
  param_1[0x3a] = 0x7f7fffff;
  param_1[0x3b] = 0x7f7fffff;
  param_1[0x3c] = 0x7f7fffff;
  param_1[0x3d] = 0x7f7fffff;
  param_1[0x3e] = 0x7f7fffff;
  param_1[0x40] = param_6;
  param_1[0x41] = param_7;
  param_1[0x43] = param_9;
  param_1[0x42] = param_8;
  param_1[0x44] = param_10;
  param_1[0x45] = param_11;
  param_1[0x4a] = 0;
  param_1[0x34] = in_ECX;
  param_1[0x39] = (int)-(param_3 * 0.5);
  param_1[0x3a] = (int)-(param_4 * 0.5);
  param_1[0x3b] = (int)-(param_5 * 0.5);
  param_1[0x3c] = (int)(param_3 * 0.5);
  param_1[0x3d] = (int)(param_4 * 0.5);
  param_1[0x3e] = (int)(param_5 * 0.5);
  param_1[0x30] = param_2;
  iVar2 = FUN_0087dc3d(-(uint)((int)((ulonglong)in_ECX * 0x5c >> 0x20) != 0) |
                       (uint)((ulonglong)in_ECX * 0x5c),uVar1);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar4 = in_ECX - 1;
    if (-1 < iVar4) {
      puVar3 = (undefined4 *)(iVar2 + 0x34);
      do {
        puVar3[-1] = 0;
        *(undefined1 *)(puVar3 + 9) = 0;
        *puVar3 = 0;
        puVar3 = puVar3 + 0x17;
        iVar4 = iVar4 + -1;
      } while (-1 < iVar4);
    }
  }
  param_1[0x32] = iVar2;
  param_1[0x33] = 0;
  param_1[0x36] = 0x1000;
  param_1[0x37] = 0;
  param_1[0x38] = 0x200;
  if (0 < (int)in_ECX) {
    do {
      uVar1 = param_1[0x33];
      if (uVar1 < (uint)param_1[0x34]) {
        param_1[0x33] = uVar1 + 1;
        (**(code **)(*param_1 + 0x28))(uVar1 * 0x5c + param_1[0x32]);
      }
      in_ECX = in_ECX - 1;
    } while (in_ECX != 0);
  }
  ExceptionList = local_10;
  return param_1;
}

