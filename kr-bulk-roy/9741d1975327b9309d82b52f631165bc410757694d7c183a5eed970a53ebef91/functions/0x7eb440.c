
undefined4 FUN_007eb440(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  
  if (in_ECX == 0) {
    return 0;
  }
  FUN_0072e2e0("LightSystem");
  iVar2 = FUN_0072e2e0("FogList");
  FUN_0072e2e0("CameraList");
  iVar3 = FUN_0072e2e0("Skybox");
  iVar4 = FUN_0072e2e0("ParticleList");
  iVar5 = FUN_0072e360();
  uVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x54) + 0xc);
  FUN_007eb530(param_1);
  if (iVar2 != 0) {
    FUN_007ebe30(uVar1);
  }
  FUN_007ec080(param_1);
  if (iVar3 != 0) {
    FUN_007ec3a0(iVar3,uVar1);
  }
  if (iVar4 != 0) {
    FUN_007ec9f0(iVar4);
  }
  while (iVar5 != 0) {
    FUN_007ed4c0(param_1);
    iVar5 = FUN_0072e3c0();
  }
  return 1;
}

