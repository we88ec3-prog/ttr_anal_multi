
undefined4 FUN_0080fdd0(int *param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  *(int **)(in_ECX + 4) = param_1;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar1 = (**(code **)(*param_1 + 0x10))();
  *(uint *)(in_ECX + 0x14) = (-(uint)(iVar1 != 1) & 2) + 0x1101;
  alGenBuffers(2,in_ECX + 8);
  FUN_00810080();
  puVar2 = (undefined4 *)(in_ECX + 0x10);
  alGenSources(1,puVar2);
  FUN_00810080();
  alSource3f(*puVar2,0x1004,0,0,0);
  alSource3f(*puVar2,0x1006,0,0,0);
  alSource3f(*puVar2,0x1005,0,0,0);
  alSourcef(*puVar2,0x1021,0);
  alSourcei(*puVar2,0x202,1);
  alSourcef(*puVar2,0x100a,0);
  FUN_00810080();
  return 1;
}

