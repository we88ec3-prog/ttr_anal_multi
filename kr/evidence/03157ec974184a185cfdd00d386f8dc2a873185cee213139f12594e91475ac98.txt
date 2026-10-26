
void FUN_004af1f0(int param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  ushort *puVar8;
  int iStack_4c;
  uint local_48;
  uint local_44;
  float fStack_3c;
  float local_38;
  float afStack_34 [6];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936e6a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_4c;
  fVar3 = (float)(DAT_00d61f20 ^ (uint)&stack0xffffffa8);
  ExceptionList = &local_14;
  if (param_2 < 2) {
    uVar7 = 0;
  }
  else {
    uVar7 = (param_2 - 2) / 0x18;
  }
  if (uVar7 != 0) {
    puVar8 = (ushort *)(param_1 + 4);
    local_44 = uVar7;
    do {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 0;
        FUN_004dec90(fVar3);
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_48 = (uint)*puVar8;
      pfVar4 = (float *)FUN_0082ef00(&local_48);
      if (*pfVar4 == DAT_00fab13c) {
        uVar1 = puVar8[2];
        iVar5 = FUN_00891268(0x138);
        if (iVar5 == 0) {
          piVar6 = (int *)0x0;
        }
        else {
          piVar6 = (int *)FUN_004cbff0(puVar8[1]);
        }
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 1;
          FUN_004dec90();
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        local_48 = (uint)puVar8[-1];
        FUN_0082ef00(&local_48);
        if ((local_38 != DAT_00fab13c) && (iVar5 = *(int *)((int)local_38 + 0x10), iVar5 != 0)) {
          piVar6[0x27] = *(int *)(iVar5 + 0x9c);
          piVar6[0x24] = *(int *)(iVar5 + 0x90);
          *(ushort *)(piVar6 + 1) = *puVar8;
          (**(code **)(*piVar6 + 0x3c))(uVar1 | 0x2000000);
          if (*(char *)((int)puVar8 + 0x11) == '\x01') {
            uVar1 = puVar8[9];
            piVar6[0x3d] = 1;
            piVar6[0x3e] = 0;
            *(ushort *)(piVar6 + 0x4a) = uVar1;
          }
          else if (*(char *)((int)puVar8 + 0x11) == '\x02') {
            uVar1 = puVar8[9];
            uVar2 = puVar8[10];
            piVar6[0x3d] = 1;
            piVar6[0x3e] = 1;
            piVar6[0x4a] = (int)(float)uVar1;
            piVar6[0x4b] = (int)(float)uVar2;
          }
          local_38 = (float)(int)(short)puVar8[3];
          afStack_34[0] = (float)(int)(short)puVar8[4];
          (**(code **)(*piVar6 + 0x44))(&local_38,1);
          (**(code **)(*piVar6 + 0x58))((char)puVar8[7]);
          (**(code **)(*piVar6 + 0x5c))(*(undefined4 *)(puVar8 + 5));
          fVar3 = (float)*(ushort *)((int)puVar8 + 0xf) / 1000.0;
          piVar6[0x4c] = (int)fVar3;
          local_38 = (float)(int)(short)puVar8[4];
          fStack_3c = (float)(int)(short)puVar8[3];
          afStack_34[0] = 0.0;
          (**(code **)*DAT_00fba838)(fStack_3c,local_38,afStack_34,0);
          piVar6[0x40] = iStack_4c;
          piVar6[0x41] = local_48;
          piVar6[0x42] = local_44;
          (**(code **)(*piVar6 + 0x30))();
          if ((DAT_00fab22c & 1) == 0) {
            DAT_00fab22c = DAT_00fab22c | 1;
            local_c = 2;
            FUN_004dec90();
            _atexit((_func_4879 *)&LAB_00bcce30);
            local_c = 0xffffffff;
          }
          FUN_004dff30(&DAT_00fab130);
        }
      }
      puVar8 = puVar8 + 0xc;
      local_44 = local_44 - 1;
    } while (local_44 != 0);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&iStack_4c);
  return;
}

