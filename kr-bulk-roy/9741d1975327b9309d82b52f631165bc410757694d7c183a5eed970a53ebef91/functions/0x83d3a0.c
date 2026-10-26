
void FUN_0083d3a0(int *param_1)

{
  int *piVar1;
  int *in_ECX;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 auStack_dc [4];
  int *local_d8;
  int *piStack_d4;
  int iStack_d0;
  uint uStack_cc;
  undefined4 auStack_c8 [30];
  undefined4 auStack_50 [17];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_dc;
  local_d8 = in_ECX;
  if (in_ECX[0xf] != 0) {
    (**(code **)(*param_1 + 0x118))();
  }
  if (in_ECX[0x1c] == 0) {
    if (DAT_00fba930 != in_ECX[0x16]) {
      (**(code **)(*(int *)param_1[0x3b] + 0x15c))((int *)param_1[0x3b],in_ECX[0x16]);
      DAT_00fba930 = in_ECX[0x16];
    }
    (**(code **)(*(int *)param_1[0x3b] + 0x1a0))((int *)param_1[0x3b],in_ECX[0x15]);
    (**(code **)(*(int *)param_1[0x3b] + 400))
              ((int *)param_1[0x3b],0,in_ECX[0x14],in_ECX[0x1a],in_ECX[0x17]);
    if (in_ECX[0x18] != 0) {
      piVar1 = (int *)in_ECX[0xe];
      piStack_d4 = piVar1;
      if (piVar1 == (int *)0x0) {
        (**(code **)(*param_1 + 0x110))(in_ECX + 1);
        iVar2 = in_ECX[0x18] + *in_ECX * 0x14;
        (**(code **)(*(int *)param_1[0x3b] + 0x148))
                  ((int *)param_1[0x3b],in_ECX[0x13],*(undefined4 *)(iVar2 + 0xc),0,
                   *(undefined4 *)(iVar2 + 0x10),*(int *)(iVar2 + 4) * 3,
                   *(undefined4 *)(in_ECX[0x18] + 8 + *in_ECX * 0x14));
      }
      else {
        if (piVar1[6] == 0) {
          (**(code **)(*(int *)param_1[0x3b] + 0xe4))((int *)param_1[0x3b],0x8f,1);
          (**(code **)(*(int *)param_1[0x3b] + 0xe4))((int *)param_1[0x3b],0x97,param_1[0x117] + -1)
          ;
          iVar2 = *piVar1;
          iVar5 = piStack_d4[1] - iVar2 >> 0x1f;
          uStack_cc = 0;
          if ((piStack_d4[1] - iVar2) / 0x34 + iVar5 != iVar5) {
            iStack_d0 = 0;
            do {
              FUN_007e7dd0(iStack_d0 + iVar2);
              FUN_0079c530();
              uVar4 = uStack_cc;
              piVar1 = (int *)param_1[0x3b];
              puVar3 = auStack_c8;
              puVar6 = auStack_50;
              for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
                *puVar6 = *puVar3;
                puVar3 = puVar3 + 1;
                puVar6 = puVar6 + 1;
              }
              (**(code **)(*piVar1 + 0xb0))(piVar1,uStack_cc + 0x100,auStack_50);
              iVar2 = *piStack_d4;
              iStack_d0 = iStack_d0 + 0x34;
              uStack_cc = uVar4 + 1;
              in_ECX = local_d8;
            } while (uStack_cc < (uint)((piStack_d4[1] - iVar2) / 0x34));
          }
        }
        piVar1 = piStack_d4;
        iVar2 = in_ECX[0x18] + *in_ECX * 0x14;
        (**(code **)(*(int *)param_1[0x3b] + 0x148))
                  (param_1[0x3b],in_ECX[0x13],*(undefined4 *)(iVar2 + 0xc),0,
                   *(undefined4 *)(iVar2 + 0x10),(*(int *)(iVar2 + 4) + piStack_d4[4]) * 3,
                   piStack_d4[5]);
        if (piVar1[6] == 0) {
          (**(code **)(*(int *)param_1[0x3b] + 0xe4))((int *)param_1[0x3b],0x8f,0);
          (**(code **)(*(int *)param_1[0x3b] + 0xe4))((int *)param_1[0x3b],0x97,0);
        }
      }
    }
  }
  else {
    FUN_0083e0c0(param_1);
  }
  uVar4 = 0;
  if (DAT_00fbac90 - DAT_00fbac8c >> 3 != 0) {
    do {
      (**(code **)(*(int *)param_1[0x3b] + 0xe4))
                ((int *)param_1[0x3b],*(undefined4 *)(DAT_00fbac8c + uVar4 * 8),
                 *(undefined4 *)(DAT_00fbac8c + 4 + uVar4 * 8));
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(DAT_00fbac90 - DAT_00fbac8c >> 3));
  }
  if (DAT_00fbac8c != DAT_00fbac90) {
    DAT_00fbac90 = DAT_00fbac8c;
  }
  iVar2 = DAT_00fbaca0 - DAT_00fbac9c >> 0x1f;
  iVar5 = 0;
  local_d8 = (int *)0x0;
  if ((DAT_00fbaca0 - DAT_00fbac9c) / 0xc + iVar2 != iVar2) {
    do {
      (**(code **)(*(int *)param_1[0x3b] + 0x10c))
                ((int *)param_1[0x3b],*(undefined4 *)(iVar5 + DAT_00fbac9c),
                 *(undefined4 *)(iVar5 + 4 + DAT_00fbac9c),*(undefined4 *)(iVar5 + 8 + DAT_00fbac9c)
                );
      local_d8 = (int *)((int)local_d8 + 1);
      iVar5 = iVar5 + 0xc;
    } while (local_d8 < (uint)((DAT_00fbaca0 - DAT_00fbac9c) / 0xc));
  }
  if (DAT_00fbac9c != DAT_00fbaca0) {
    DAT_00fbaca0 = DAT_00fbac9c;
  }
  iVar2 = DAT_00fbacb0 - DAT_00fbacac >> 0x1f;
  iVar5 = 0;
  local_d8 = (int *)0x0;
  if ((DAT_00fbacb0 - DAT_00fbacac) / 0xc + iVar2 != iVar2) {
    do {
      (**(code **)(*(int *)param_1[0x3b] + 0x114))
                ((int *)param_1[0x3b],*(undefined4 *)(iVar5 + DAT_00fbacac),
                 *(undefined4 *)(iVar5 + 4 + DAT_00fbacac),*(undefined4 *)(iVar5 + 8 + DAT_00fbacac)
                );
      local_d8 = (int *)((int)local_d8 + 1);
      iVar5 = iVar5 + 0xc;
    } while (local_d8 < (uint)((DAT_00fbacb0 - DAT_00fbacac) / 0xc));
  }
  if (DAT_00fbacac != DAT_00fbacb0) {
    DAT_00fbacb0 = DAT_00fbacac;
  }
  __security_check_cookie(local_c ^ (uint)auStack_dc);
  return;
}

