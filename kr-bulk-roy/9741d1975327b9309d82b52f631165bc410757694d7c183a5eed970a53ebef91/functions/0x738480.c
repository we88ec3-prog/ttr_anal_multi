
/* WARNING: Removing unreachable block (ram,0x007384ba) */
/* WARNING: Removing unreachable block (ram,0x007384c0) */
/* WARNING: Removing unreachable block (ram,0x007384d1) */
/* WARNING: Removing unreachable block (ram,0x007384d3) */

void FUN_00738480(int *param_1,void *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  size_t _Size;
  undefined4 local_84 [8];
  undefined2 local_64;
  int *local_60;
  int local_5c;
  int *local_58;
  int local_54;
  int *local_50;
  void *local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_60 = param_1;
  local_4c = param_2;
  iVar4 = *(int *)(in_ECX + 0x10);
  if (iVar4 != *(int *)(in_ECX + 0x14)) {
    *(int *)(in_ECX + 0x14) = iVar4;
    local_48 = iVar4;
  }
  local_5c = in_ECX;
  piVar1 = (int *)FUN_00714770(param_2,&DAT_00bed1e0);
  local_58 = piVar1;
  if (piVar1 != (int *)0x0) {
    local_84[6] = 0;
    local_84[7] = 0;
    local_84[2] = 1;
    local_84[3] = 1;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_64 = 0;
    local_84[0] = 0;
    local_84[1] = 0;
    local_84[4] = 0;
    local_84[5] = 0;
    (**(code **)(*piVar1 + 0x10))(&local_28,1,0x1e);
    (**(code **)(*piVar1 + 0x10))(&local_54,1,4);
    local_48 = 0x22;
    local_4c = (void *)0x0;
    if (0 < local_54) {
      do {
        (**(code **)(*piVar1 + 0x10))(local_84,1,0x24);
        local_48 = local_48 + 0x24;
        if ((local_84 < *(undefined4 **)(in_ECX + 0x14)) &&
           (puVar2 = *(undefined4 **)(in_ECX + 0x10), puVar2 <= local_84)) {
          if (*(int *)(in_ECX + 0x14) == *(int *)(in_ECX + 0x18)) {
            FUN_0084a0e0();
          }
          puVar5 = (undefined4 *)
                   (*(int *)(in_ECX + 0x10) + (((int)local_84 - (int)puVar2) / 0x24) * 0x24);
          puVar2 = *(undefined4 **)(in_ECX + 0x14);
          if (puVar2 != (undefined4 *)0x0) {
LAB_007385e5:
            for (iVar4 = 9; piVar1 = local_58, iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar2 = *puVar5;
              puVar5 = puVar5 + 1;
              puVar2 = puVar2 + 1;
            }
          }
        }
        else {
          if (*(undefined4 **)(in_ECX + 0x14) == *(undefined4 **)(in_ECX + 0x18)) {
            FUN_0084a0e0();
          }
          puVar2 = *(undefined4 **)(in_ECX + 0x14);
          if (puVar2 != (undefined4 *)0x0) {
            puVar5 = local_84;
            goto LAB_007385e5;
          }
        }
        *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 0x24;
        local_4c = (void *)((int)local_4c + 1);
      } while ((int)local_4c < local_54);
    }
    iVar4 = (**(code **)(*piVar1 + 0x2c))();
    _Size = iVar4 - local_48;
    pvVar3 = _malloc(_Size);
    local_4c = pvVar3;
    (**(code **)(*piVar1 + 0x10))(pvVar3,1,_Size);
    iVar4 = D3DXGetImageInfoFromFileInMemory(pvVar3,_Size,&local_44);
    if (iVar4 == 0) {
      *(undefined4 *)(local_5c + 0x24) = local_40;
      *(undefined4 *)(local_5c + 0x20) = local_44;
      (**(code **)(*local_60 + 0xc))(local_60,&local_50);
      iVar4 = D3DXCreateTextureFromFileInMemoryEx
                        (local_50,local_4c,_Size,local_44,local_40,0xffffffff,0,0,1,1,0xffffffff,0,0
                         ,0,local_5c + 0xc);
      (**(code **)(*local_50 + 8))(local_50);
      if (iVar4 != 0) {
        (**(code **)(*piVar1 + 4))();
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      *(undefined1 *)(local_5c + 4) = 1;
      (**(code **)(*piVar1 + 4))();
      _free(local_4c);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    (**(code **)(*piVar1 + 4))();
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

