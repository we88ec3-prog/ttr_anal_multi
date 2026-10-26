
void FUN_007526b0(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *in_ECX;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int *local_dc;
  int *local_d8;
  int *local_d4;
  float local_d0;
  undefined1 local_cc [64];
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (in_ECX[0x4f1] != 0) {
    (**(code **)(*(int *)in_ECX[7] + 0xb4))((int *)in_ECX[7],0x100,local_cc);
    (**(code **)(*(int *)in_ECX[7] + 0xb4))((int *)in_ECX[7],2,local_8c);
    (**(code **)(*(int *)in_ECX[7] + 0xb4))((int *)in_ECX[7],3,local_4c);
    (**(code **)(*(int *)in_ECX[7] + 0xb0))((int *)in_ECX[7],0x100,in_ECX + 8);
    (**(code **)(*(int *)in_ECX[7] + 0xb0))((int *)in_ECX[7],2,in_ECX + 8);
    (**(code **)(*(int *)in_ECX[7] + 0xb0))((int *)in_ECX[7],3,in_ECX + 0x18);
    piVar7 = (int *)in_ECX[0x52d];
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 0x10))(piVar7);
    }
    piVar7 = (int *)in_ECX[0x52e];
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 0x14))(piVar7);
    }
    if ((char)in_ECX[0x52f] != '\0') {
      FUN_00750970();
      if (in_ECX[0x51e] != 0) {
        local_dc = (int *)0x0;
        local_d4 = (int *)0x0;
        (**(code **)(*(int *)in_ECX[7] + 0x98))((int *)in_ECX[7],0,&local_dc);
        (**(code **)(*(int *)in_ECX[7] + 0xa0))((int *)in_ECX[7],&local_d4);
        (**(code **)(*(int *)in_ECX[7] + 0x94))((int *)in_ECX[7],0,in_ECX[5]);
        (**(code **)(*(int *)in_ECX[7] + 0x9c))((int *)in_ECX[7],0);
        local_d8 = (int *)in_ECX[0x51e];
        piVar7 = (int *)in_ECX[0x51d];
        piVar3 = (int *)*piVar7;
        iVar1 = FUN_0087dc3d(-(uint)((int)(ZEXT48(local_d8) * 0x10 >> 0x20) != 0) |
                             (uint)(ZEXT48(local_d8) * 0x10));
        if (piVar3 != piVar7) {
          puVar6 = (undefined4 *)(iVar1 + 4);
          do {
            local_d0 = (float)piVar3[2] * (float)in_ECX[0x4e7];
            FUN_0043c810(local_d0);
            uVar2 = FUN_008fed10();
            puVar6[-1] = uVar2;
            local_d0 = (float)piVar3[4] * (float)in_ECX[0x4e7];
            FUN_0043c810(local_d0);
            uVar2 = FUN_008fed10();
            puVar6[1] = uVar2;
            local_d0 = (float)piVar3[3] * (float)in_ECX[0x4e8];
            FUN_0043c810(local_d0);
            uVar2 = FUN_008fed10();
            *puVar6 = uVar2;
            local_d0 = (float)piVar3[5] * (float)in_ECX[0x4e8];
            FUN_0043c810(local_d0);
            uVar2 = FUN_008fed10();
            puVar6[2] = uVar2;
            piVar3 = (int *)*piVar3;
            puVar6 = puVar6 + 4;
          } while (piVar3 != piVar7);
        }
        (**(code **)(*(int *)in_ECX[7] + 0xac))((int *)in_ECX[7],local_d8,iVar1,1,0,0,0);
        FUN_00891d3d(iVar1);
        if (in_ECX[0x4f1] != 0) {
          FUN_00760fc0(in_ECX + 0x51d);
        }
        (**(code **)(*(int *)in_ECX[7] + 0x94))((int *)in_ECX[7],0,local_dc);
        (**(code **)(*(int *)in_ECX[7] + 0x9c))((int *)in_ECX[7],local_d4);
        (**(code **)(*local_dc + 8))(local_dc);
        (**(code **)(*local_d4 + 8))(local_d4);
      }
      piVar7 = (int *)in_ECX[0x51d];
      piVar3 = (int *)*piVar7;
      *piVar7 = (int)piVar7;
      *(int *)(in_ECX[0x51d] + 4) = in_ECX[0x51d];
      in_ECX[0x51e] = 0;
      if (piVar3 != (int *)in_ECX[0x51d]) {
        do {
          piVar7 = (int *)*piVar3;
          FUN_0089120c(piVar3);
          piVar3 = piVar7;
        } while (piVar7 != (int *)in_ECX[0x51d]);
      }
      *(undefined1 *)(in_ECX + 0x52f) = 0;
    }
    (**(code **)(*in_ECX + 0x2c))();
    if ((int *)in_ECX[0x596d] != (int *)0x0) {
      (**(code **)(*(int *)in_ECX[0x596d] + 0x18))();
    }
    iVar1 = FUN_008fed10();
    local_d4 = (int *)FUN_008fed10();
    local_d8 = (int *)(float)in_ECX[0x28];
    uVar2 = FUN_008fed10();
    uVar4 = FUN_008fed10();
    if (in_ECX[0x4f2] != 0) {
      local_d8 = (int *)FUN_00443da0();
      uVar8 = 0;
      uVar9 = 0;
      piVar7 = in_ECX + 0x4eb;
      uVar10 = uVar2;
      uVar11 = uVar4;
      iVar5 = FUN_00443da0(piVar7,0,0,uVar2,uVar4);
      FUN_00748a20(((in_ECX[0x2a] - in_ECX[0x36]) - *local_d8) + iVar1,
                   ((in_ECX[0x2b] - in_ECX[0x37]) - *(int *)(iVar5 + 4)) + (int)local_d4,piVar7,
                   uVar8,uVar9,uVar10,uVar11);
    }
    if (in_ECX[0x4fc] != 0) {
      FUN_00748a20(iVar1,local_d4,in_ECX + 0x4eb,0,0,uVar2,uVar4);
    }
    if (in_ECX[0x4fb] != 0) {
      FUN_00748a20(iVar1,local_d4,in_ECX + 0x4eb,0,0,uVar2,uVar4);
    }
    piVar7 = (int *)in_ECX[0x52d];
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 0x14))(piVar7);
    }
    (**(code **)(*(int *)in_ECX[7] + 0xb0))((int *)in_ECX[7],0x100,local_cc);
    (**(code **)(*(int *)in_ECX[7] + 0xb0))((int *)in_ECX[7],2,local_8c);
    (**(code **)(*(int *)in_ECX[7] + 0xb0))((int *)in_ECX[7],3,local_4c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

