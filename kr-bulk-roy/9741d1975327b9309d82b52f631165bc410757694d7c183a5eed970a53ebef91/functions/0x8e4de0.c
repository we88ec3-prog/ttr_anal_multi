
void FUN_008e4de0(int *param_1,uint param_2)

{
  undefined2 *puVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  byte bVar7;
  uint in_ECX;
  int in_EDX;
  int iVar8;
  int iVar9;
  int *piVar10;
  int local_404;
  int local_400;
  uint local_3f8;
  int local_3f4;
  int local_3f0;
  int local_3ec;
  int local_3e8;
  int *local_3e4;
  ushort local_3e0;
  char cStack_3dd;
  int local_3dc;
  undefined1 local_3d8;
  char local_3d7;
  uint local_3d4;
  uint local_3d0 [9];
  uint local_3ac;
  uint local_3a4;
  uint local_3a0;
  undefined1 local_38a;
  int local_388;
  undefined4 local_e4;
  undefined1 local_db;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar9 = *(int *)(in_EDX + 4);
  iVar8 = *(int *)(iVar9 + 0x290);
  local_3e4 = param_1;
  local_3d7 = '\0';
  local_3e8 = iVar8;
  local_3dc = iVar9;
  local_3d4 = in_ECX;
  if ((*(int *)(iVar8 + 0x5b0) == 0xffff) || (*(int *)(iVar8 + 0x48c) == 0)) {
    if (*(uint *)(iVar8 + 0xc) <= in_ECX) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  else if ((in_ECX != 0) && (local_3d4 = FUN_008de250(), local_3d4 == 0)) goto LAB_008e4e51;
  if ((param_2 & 0x400) != 0) {
    param_2 = param_2 | 3;
  }
  *(undefined4 *)(in_EDX + 0xa4) = 0x10000;
  *(undefined4 *)(in_EDX + 0xa8) = 0x10000;
  if (local_3e4 != (int *)0x0) {
    *(int *)(in_EDX + 0xa4) = local_3e4[4];
    *(int *)(in_EDX + 0xa8) = local_3e4[5];
    local_3d0[0] = *(uint *)(*local_3e4 + 0x214);
    local_3ec = *(int *)(*local_3e4 + 0x68);
    local_3f8 = local_3e4[0xb];
    if ((((local_3f8 != -1) && (*(int *)(local_3d0[0] + 0x60) != 0)) && ((param_2 & 8) == 0)) &&
       (iVar4 = (**(code **)(local_3d0[0] + 0x48))
                          (iVar9,local_3f8,local_3d4,param_2,local_3ec,in_EDX + 0x4c,&local_18),
       uVar5 = local_3d4, iVar4 == 0)) {
      *(undefined4 *)(in_EDX + 0x6c) = 0;
      *(uint *)(in_EDX + 0x18) = (local_18 >> 0x10) << 6;
      *(uint *)(in_EDX + 0x1c) = (local_18 & 0xffff) << 6;
      *(int *)(in_EDX + 0x20) = (int)(short)local_14 << 6;
      *(int *)(in_EDX + 0x24) = (int)local_14._2_2_ << 6;
      *(uint *)(in_EDX + 0x28) = (local_10 & 0xffff) << 6;
      *(int *)(in_EDX + 0x2c) = (int)local_10._2_2_ << 6;
      *(int *)(in_EDX + 0x30) = (int)(short)local_c << 6;
      *(uint *)(in_EDX + 0x34) = (local_c >> 0x10) << 6;
      *(undefined4 *)(in_EDX + 0x48) = 0x62697473;
      if ((param_2 & 0x10) == 0) {
        *(int *)(in_EDX + 100) = (int)(short)local_14;
        *(int *)(in_EDX + 0x68) = (int)local_14._2_2_;
      }
      else {
        *(int *)(in_EDX + 100) = (int)local_10._2_2_;
        *(int *)(in_EDX + 0x68) = (int)(short)local_c;
      }
      (**(code **)(*(int *)(iVar9 + 0x214) + 0x70))(iVar9,0,local_3d4,&local_3d8,&local_3e0);
      *(uint *)(in_EDX + 0x38) = (uint)local_3e0;
      if ((*(char *)(iVar9 + 0x124) != '\0') && (*(short *)(iVar9 + 0x14a) != 0)) {
        (**(code **)(*(int *)(iVar9 + 0x214) + 0x70))(iVar9,1,uVar5,&local_3d8,&local_3e0);
        *(uint *)(in_EDX + 0x3c) = (uint)local_3e0;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      if (*(short *)(iVar9 + 0x16c) != -1) {
        *(int *)(in_EDX + 0x3c) = (int)*(short *)(iVar9 + 0x1b2) - (int)*(short *)(iVar9 + 0x1b4);
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      *(int *)(in_EDX + 0x3c) = (int)*(short *)(iVar9 + 0xdc) - (int)*(short *)(iVar9 + 0xde);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  if ((param_2 & 0x4000) != 0) {
LAB_008e4e51:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (*(int *)(iVar8 + 0x768) == 0) {
    local_28 = *(int *)(iVar8 + 0x55c);
    local_24 = *(int *)(iVar8 + 0x560);
    local_20 = *(int *)(iVar8 + 0x564);
    local_1c = *(int *)(iVar8 + 0x568);
    local_404 = *(int *)(iVar8 + 0x574);
    local_400 = *(int *)(iVar8 + 0x578);
  }
  else {
    uVar5 = FUN_008de130(local_3d4);
    if (*(uint *)(iVar8 + 0x768) <= (uVar5 & 0xff)) {
      uVar5 = (uint)(byte)(*(char *)(iVar8 + 0x768) - 1);
    }
    iVar4 = *(int *)(iVar8 + 0x570);
    iVar9 = *(int *)(iVar8 + 0x76c + (uVar5 & 0xff) * 4);
    local_28 = *(int *)(iVar9 + 0x30);
    iVar2 = *(int *)(iVar9 + 0x44);
    local_24 = *(int *)(iVar9 + 0x34);
    local_20 = *(int *)(iVar9 + 0x38);
    local_1c = *(int *)(iVar9 + 0x3c);
    iVar9 = *(int *)(iVar8 + 0x76c + (uVar5 & 0xff) * 4);
    local_404 = *(int *)(iVar9 + 0x48);
    local_400 = *(int *)(iVar9 + 0x4c);
    iVar9 = local_3dc;
    if (iVar4 != iVar2) {
      uVar6 = FUN_008b7dc0(*(undefined4 *)(in_EDX + 0xa4),iVar4,iVar2);
      *(undefined4 *)(in_EDX + 0xa4) = uVar6;
      uVar6 = FUN_008b7dc0(*(undefined4 *)(in_EDX + 0xa8),iVar4,iVar2);
      *(undefined4 *)(in_EDX + 0xa8) = uVar6;
      local_3d7 = '\x01';
      iVar9 = local_3dc;
    }
  }
  *(undefined2 *)(in_EDX + 0x6e) = 0;
  puVar1 = (undefined2 *)(in_EDX + 0x6c);
  *puVar1 = 0;
  bVar7 = ~(byte)(param_2 >> 1);
  local_3f8 = CONCAT31(local_3f8._1_3_,bVar7) & 0xffffff01;
  *(byte *)(in_EDX + 0xa0) = bVar7 & 1;
  *(byte *)(in_EDX + 0xa1) = ~(byte)param_2 & 1;
  *(undefined4 *)(in_EDX + 0x48) = 0x6f75746c;
  FUN_008e0180(iVar9,local_3e4,local_3f8,(int)param_2 >> 0x10 & 0xf);
  iVar9 = local_3dc;
  if ((param_2 & 0x100) != 0) {
    local_db = 1;
  }
  local_38a = 0;
  local_3dc = FUN_008e04c0();
  if ((local_3dc != 0) ||
     (local_3dc = FUN_008e01f0(local_3e4,local_3d4), uVar5 = local_3d0[0], local_3dc != 0))
  goto LAB_008e5781;
  local_3dc = FUN_008e4c10(local_3d0[0]);
  if ((char)local_3dc == -0x5c) {
    local_3f8 = 0;
    local_3d7 = '\x01';
    *(undefined1 *)(in_EDX + 0xa0) = 0;
    local_3dc = FUN_008e4c10(uVar5);
  }
  FUN_008e0520(uVar5);
  iVar8 = 0;
  if (local_3dc != 0) goto LAB_008e5781;
  if (*(int *)(*(int *)(iVar9 + 0x80) + 0x30) == 0) {
    if (*(int *)(local_3e8 + 0x4b0) != 0) {
      iVar8 = *(int *)(*(int *)(local_3e8 + 0x4b0) + local_3d4 * 4) + -1 +
              *(int *)(local_3e8 + 0x4b4);
      *(uint *)(in_EDX + 0x8c) = uVar5;
      goto LAB_008e5321;
    }
  }
  else {
    *(undefined4 *)(in_EDX + 0x8c) = 0;
LAB_008e5321:
    *(int *)(in_EDX + 0x88) = iVar8;
  }
  FUN_008e0120();
  piVar10 = *(int **)(*(int *)(iVar9 + 0x80) + 0x30);
  if ((piVar10 != (int *)0x0) && (*(int *)(*piVar10 + 8) != 0)) {
    local_18 = local_3ac;
    local_14 = 0;
    local_10 = local_3a4;
    local_c = local_3a0;
    piVar10 = *(int **)(*(int *)(iVar9 + 0x80) + 0x30);
    local_3dc = (**(code **)(*piVar10 + 8))(piVar10[1],local_3d4,0,&local_18);
    local_3ac = local_18;
    local_3a4 = local_10;
    local_3a0 = local_c;
    if (local_3dc != 0) goto LAB_008e5781;
  }
  if ((param_2 & 0x400) != 0) {
    iVar9 = *(int *)(in_EDX + 0x9c);
    *(uint *)(in_EDX + 0x20) = local_3ac;
    *(undefined4 *)(in_EDX + 0x28) = local_e4;
    *(int *)(iVar9 + 0xc) = local_28;
    *(int *)(iVar9 + 0x10) = local_24;
    *(int *)(iVar9 + 0x14) = local_20;
    *(int *)(iVar9 + 0x18) = local_1c;
    *(int *)(iVar9 + 0x1c) = local_404;
    *(int *)(iVar9 + 0x20) = local_400;
    *(undefined1 *)(iVar9 + 8) = 1;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *(undefined4 *)(in_EDX + 0x28) = local_e4;
  *(undefined4 *)(in_EDX + 0x38) = local_e4;
  *(undefined1 *)(*(int *)(in_EDX + 0x9c) + 8) = 0;
  if ((*(char *)(iVar9 + 0x124) == '\0') || (*(short *)(iVar9 + 0x14a) == 0)) {
    cStack_3dd = '\0';
    if (*(short *)(iVar9 + 0x16c) == -1) {
      *(int *)(in_EDX + 0x34) = (int)*(short *)(iVar9 + 0xdc) - (int)*(short *)(iVar9 + 0xde);
    }
    else {
      *(int *)(in_EDX + 0x34) = (int)*(short *)(iVar9 + 0x1b2) - (int)*(short *)(iVar9 + 0x1b4);
    }
  }
  else {
    local_3ec = 0;
    local_3d0[0] = 0;
    cStack_3dd = '\x01';
    (**(code **)(*(int *)(iVar9 + 0x214) + 0x70))(iVar9,1,local_3d4,&local_3ec,local_3d0);
    *(int *)(in_EDX + 0x30) = (int)(short)local_3ec;
    *(uint *)(in_EDX + 0x34) = local_3d0[0] & 0xffff;
  }
  *(undefined4 *)(in_EDX + 0x3c) = *(undefined4 *)(in_EDX + 0x34);
  *(undefined4 *)(in_EDX + 0x48) = 0x6f75746c;
  *(undefined4 *)(in_EDX + 0x7c) = 0;
  if ((local_3e4 != (int *)0x0) && (*(ushort *)((int)local_3e4 + 0xe) < 0x18)) {
    *(undefined4 *)(in_EDX + 0x7c) = 0x100;
  }
  *(uint *)(in_EDX + 0x7c) = *(uint *)(in_EDX + 0x7c) | 4;
  if ((((local_28 != 0x10000) || (local_1c != 0x10000)) || (local_24 != 0)) || (local_20 != 0)) {
    FUN_008b9570(puVar1,&local_28);
  }
  if ((local_404 != 0) || (local_400 != 0)) {
    FUN_008b94d0(puVar1,local_404,local_400);
  }
  local_3f4 = *(int *)(in_EDX + 0x28);
  local_3f0 = 0;
  FUN_008b9510(&local_3f4,&local_28);
  local_3f0 = *(int *)(in_EDX + 0x34);
  *(int *)(in_EDX + 0x28) = local_3f4 + local_404;
  local_3f4 = 0;
  FUN_008b9510(&local_3f4,&local_28);
  *(int *)(in_EDX + 0x34) = local_3f0 + local_400;
  if (((param_2 & 1) == 0) || (local_3d7 != '\0')) {
    local_3e4 = *(int **)(in_EDX + 0xa4);
    local_3d4 = *(uint *)(in_EDX + 0xa8);
    piVar10 = *(int **)(in_EDX + 0x70);
    if (((char)local_3f8 == '\0') || (local_388 == 0)) {
      for (iVar9 = (int)*(short *)(in_EDX + 0x6e); 0 < iVar9; iVar9 = iVar9 + -1) {
        lVar3 = (longlong)*piVar10 * (longlong)(int)local_3e4 +
                (ulonglong)((int)((longlong)*piVar10 * (longlong)(int)local_3e4 >> 0x3f) + 0x8000);
        *piVar10 = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
        lVar3 = (longlong)piVar10[1] * (longlong)(int)local_3d4 +
                (ulonglong)((int)((longlong)piVar10[1] * (longlong)(int)local_3d4 >> 0x3f) + 0x8000)
        ;
        local_3ec = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
        piVar10[1] = local_3ec;
        piVar10 = piVar10 + 2;
      }
    }
    lVar3 = (longlong)*(int *)(in_EDX + 0x28) * (longlong)(int)local_3e4;
    lVar3 = lVar3 + (ulonglong)((int)(lVar3 >> 0x3f) + 0x8000);
    local_3e8 = *(int *)(in_EDX + 0x34);
    *(uint *)(in_EDX + 0x28) = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
    lVar3 = (longlong)local_3e8 * (longlong)(int)local_3d4 +
            (ulonglong)((int)((longlong)local_3e8 * (longlong)(int)local_3d4 >> 0x3f) + 0x8000);
    local_3d0[0] = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
    *(uint *)(in_EDX + 0x34) = local_3d0[0];
  }
  FUN_008b9440(puVar1,&local_18);
  *(int *)(in_EDX + 0x18) = local_10 - local_18;
  *(uint *)(in_EDX + 0x1c) = local_c - local_14;
  *(uint *)(in_EDX + 0x20) = local_18;
  *(uint *)(in_EDX + 0x24) = local_c;
  if (cStack_3dd != '\0') {
    *(uint *)(in_EDX + 0x2c) = local_18 - *(int *)(in_EDX + 0x28) / 2;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((param_2 & 0x10) != 0) {
    FUN_008b86a0((int *)(in_EDX + 0x18),*(undefined4 *)(in_EDX + 0x34));
  }
LAB_008e5781:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

