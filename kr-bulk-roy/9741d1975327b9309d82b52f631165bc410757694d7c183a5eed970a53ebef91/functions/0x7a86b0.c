
void FUN_007a86b0(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  float10 fVar4;
  undefined1 local_14 [12];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar2 = (int *)**(int **)(param_1 + 0x10c);
  if (piVar2 != *(int **)(param_1 + 0x10c)) {
    do {
      piVar3 = (int *)piVar2[2];
      fVar4 = (float10)(**(code **)(*(int *)(param_1 + 4) + 0x10))();
      piVar3[0xf] = (int)(float)fVar4;
      piVar3[0x1c] = 1;
      piVar1 = (int *)(**(code **)(*(int *)(param_1 + 4) + 8))(local_14);
      piVar3[10] = *piVar1;
      piVar3[0xb] = piVar1[1];
      piVar3[0xc] = piVar1[2];
      piVar3[0x1c] = 1;
      FUN_007bd8d0(param_2);
      if (piVar3[0x1b] == 0) {
        piVar3 = (int *)*piVar2;
      }
      else {
        *(int *)(*piVar3 + 0x60) = *(int *)(*piVar3 + 0x60) + -1;
        if ((piVar3[0x1d] == 0) || (piVar3[0x1e] == 0)) {
          if (0 < piVar3[0x1d]) {
            FUN_007be0f0(piVar3);
          }
          FUN_007bd850();
          FUN_0089120c(piVar3);
        }
        else {
          FUN_007dd1a0(*piVar3,piVar3);
        }
        piVar3 = (int *)piVar2[3];
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0x10))();
          (**(code **)(*piVar3 + 8))();
        }
        piVar3 = (int *)*piVar2;
        if (piVar2 != *(int **)(param_1 + 0x10c)) {
          *(int **)piVar2[1] = piVar3;
          *(int *)(*piVar2 + 4) = piVar2[1];
          FUN_0089120c(piVar2);
          *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + -1;
        }
      }
      piVar2 = piVar3;
    } while (piVar3 != *(int **)(param_1 + 0x10c));
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

