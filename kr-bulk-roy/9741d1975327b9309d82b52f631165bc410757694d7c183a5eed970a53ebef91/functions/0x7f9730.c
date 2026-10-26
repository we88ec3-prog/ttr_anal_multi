
void FUN_007f9730(void)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  undefined4 *local_28 [2];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b8be;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX[0x33] != 0) {
    (**(code **)(*in_ECX + 0x30))(local_14);
    (**(code **)(*(int *)in_ECX[1] + 0x104))((int *)in_ECX[1],0,in_ECX[0x31]);
    (**(code **)(*(int *)in_ECX[1] + 0x104))((int *)in_ECX[1],1,0);
    (**(code **)(*(int *)in_ECX[1] + 0x104))((int *)in_ECX[1],2,0);
    (**(code **)(*(int *)in_ECX[1] + 0xb0))((int *)in_ECX[1],0x100,in_ECX + 0x10);
    (**(code **)(*(int *)in_ECX[1] + 0x164))((int *)in_ECX[1],0x42);
    (**(code **)(*(int *)in_ECX[1] + 400))((int *)in_ECX[1],0,in_ECX[0x35],0,0x10);
    if ((uint)in_ECX[0x36] <= (uint)in_ECX[0x37]) {
      in_ECX[0x37] = 0;
    }
    local_28[0] = (undefined4 *)0x0;
    (**(code **)(*(int *)in_ECX[0x35] + 0x2c))
              ((int *)in_ECX[0x35],in_ECX[0x37] << 4,in_ECX[0x38] << 4,local_28,
               (-(uint)(in_ECX[0x37] != 0) & 0xfffff000) + 0x2000);
    iVar5 = 0;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    local_3c = 0;
    if (in_ECX[0x33] != 0) {
      local_38 = 0;
      do {
        puVar6 = (undefined4 *)(in_ECX[0x32] + local_38);
        local_20 = *puVar6;
        local_1c = puVar6[1];
        local_18 = puVar6[2];
        D3DXVec3TransformCoord(&local_20,&local_20,in_ECX + 0x10);
        if ((*(char *)(puVar6 + 0x16) != '\0') &&
           ((DAT_00fb76e4 == 0 ||
            (iVar2 = FUN_00838860(local_20,local_1c,local_18,in_ECX[0x30]), iVar2 != 0)))) {
          *local_28[0] = *puVar6;
          local_28[0][1] = puVar6[1];
          local_28[0][2] = puVar6[2];
          fVar1 = (float)puVar6[0xe];
          if (NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0)) {
            if (0.0 < (float)puVar6[0xe]) {
              local_30 = (uint)(longlong)ROUND((float)puVar6[0xe] * 255.0 + 0.5);
              local_34 = local_30;
            }
            else {
              local_34 = 0;
            }
          }
          else {
            local_34 = 0xff;
          }
          fVar1 = (float)puVar6[0xf];
          if (NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0)) {
            if (0.0 < (float)puVar6[0xf]) {
              local_30 = (uint)(longlong)ROUND((float)puVar6[0xf] * 255.0 + 0.5);
              uVar4 = local_30;
            }
            else {
              uVar4 = 0;
            }
          }
          else {
            uVar4 = 0xff;
          }
          if (1.0 < (float)puVar6[0x10] == ((float)puVar6[0x10] == 1.0)) {
            if (0.0 < (float)puVar6[0x10]) {
              local_30 = (uint)(longlong)ROUND((float)puVar6[0x10] * 255.0 + 0.5);
              uVar3 = local_30;
            }
            else {
              uVar3 = 0;
            }
          }
          else {
            uVar3 = 0xff;
          }
          if (1.0 < (float)puVar6[0x11] == ((float)puVar6[0x11] == 1.0)) {
            if (0.0 < (float)puVar6[0x11]) {
              local_30 = (uint)(longlong)ROUND((float)puVar6[0x11] * 255.0 + 0.5);
            }
            else {
              local_30 = 0;
            }
          }
          else {
            local_30 = 0xff;
          }
          iVar5 = iVar5 + 1;
          local_28[0][3] = ((local_30 << 8 | local_34) << 8 | uVar4) << 8 | uVar3;
          local_28[0] = local_28[0] + 4;
          if (iVar5 == in_ECX[0x38]) {
            (**(code **)(*(int *)in_ECX[0x35] + 0x30))((int *)in_ECX[0x35]);
            (**(code **)(*(int *)in_ECX[1] + 0x144))((int *)in_ECX[1],1,in_ECX[0x37],in_ECX[0x38]);
            in_ECX[0x37] = in_ECX[0x37] + in_ECX[0x38];
            if ((uint)in_ECX[0x36] <= (uint)in_ECX[0x37]) {
              in_ECX[0x37] = 0;
            }
            (**(code **)(*(int *)in_ECX[0x35] + 0x2c))
                      ((int *)in_ECX[0x35],in_ECX[0x37] << 4,in_ECX[0x38] << 4,local_28,
                       (-(uint)(in_ECX[0x37] != 0) & 0xfffff000) + 0x2000);
            iVar5 = 0;
          }
        }
        local_38 = local_38 + 0x5c;
        local_3c = local_3c + 1;
      } while (local_3c < (uint)in_ECX[0x33]);
    }
    (**(code **)(*(int *)in_ECX[0x35] + 0x30))((int *)in_ECX[0x35]);
    if (iVar5 != 0) {
      (**(code **)(*(int *)in_ECX[1] + 0x144))((int *)in_ECX[1],1,in_ECX[0x37],iVar5);
    }
    in_ECX[0x37] = in_ECX[0x37] + in_ECX[0x38];
    (**(code **)(*in_ECX + 0x34))();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

