
void FUN_0044aa10(int *param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *in_EAX;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar4 = *param_1;
  local_10 = 0;
  if (param_1[1] - iVar4 >> 2 != 0) {
    do {
      uVar1 = *(uint *)(iVar4 + local_10 * 4);
      local_c = 0;
      do {
        if ((uVar1 & 1 << ((byte)local_c & 0x1f)) != 0) {
          uVar5 = local_10 * 0x20 + local_c;
          local_8 = uVar5 & 0xffff;
          puVar2 = (uint *)in_EAX[1];
          if (&local_8 < puVar2) {
            puVar3 = (uint *)*in_EAX;
            if (&local_8 < puVar3) goto LAB_0044aada;
            if (puVar2 == (uint *)in_EAX[2]) {
              uVar5 = (int)puVar2 - (int)puVar3 >> 1;
              if (0x7ffffffe < uVar5) goto LAB_0044ab5a;
              uVar5 = uVar5 + 1;
              uVar6 = (int)in_EAX[2] - (int)puVar3 >> 1;
              if (uVar6 < uVar5) {
                if (0x7fffffff - (uVar6 >> 1) < uVar6) {
                  uVar6 = 0;
                }
                else {
                  uVar6 = uVar6 + (uVar6 >> 1);
                }
                if (uVar6 < uVar5) {
                  uVar6 = uVar5;
                }
                FUN_0044b6a0(uVar6);
              }
            }
            if ((undefined2 *)in_EAX[1] != (undefined2 *)0x0) {
              *(undefined2 *)in_EAX[1] =
                   *(undefined2 *)(*in_EAX + ((int)&local_8 - (int)puVar3 >> 1) * 2);
            }
          }
          else {
LAB_0044aada:
            if (puVar2 == (uint *)in_EAX[2]) {
              uVar6 = (int)((int)puVar2 - *in_EAX) >> 1;
              if (0x7ffffffe < uVar6) {
LAB_0044ab5a:
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar6 = uVar6 + 1;
              uVar7 = (int)((int)in_EAX[2] - *in_EAX) >> 1;
              if (uVar7 < uVar6) {
                if (0x7fffffff - (uVar7 >> 1) < uVar7) {
                  uVar7 = 0;
                }
                else {
                  uVar7 = uVar7 + (uVar7 >> 1);
                }
                if (uVar7 < uVar6) {
                  uVar7 = uVar6;
                }
                FUN_0044b6a0(uVar7);
              }
            }
            if ((undefined2 *)in_EAX[1] != (undefined2 *)0x0) {
              *(undefined2 *)in_EAX[1] = (short)uVar5;
            }
          }
          in_EAX[1] = in_EAX[1] + 2;
        }
        local_c = local_c + 1;
      } while (local_c < 0x20);
      iVar4 = *param_1;
      local_10 = local_10 + 1;
    } while (local_10 < (uint)(param_1[1] - iVar4 >> 2));
  }
  return;
}

