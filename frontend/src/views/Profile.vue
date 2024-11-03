<template>
  <div id="app">
    <div class="bg-highlight" style="height: 3vh; width: 100%"></div>
    <div style="height: auto">
      <div class="d-flex">
        <!-- left-blank -->
        <div class="flex-fill"></div>

        <div class="flex-fill" style="height: 100vh; width: 90%">
          <!-- top side -->
          <div
            class="d-flex flex-row bg-white"
            style="height: 12vh; width: 12vw"
          >
            <img
              :src="require('@/assets/image2.png')"
              style="max-height: 100%; max-width: 100%; border-radius: 80%"
            />

            <div class="ms-3 mt-3" style="height: auto; width: auto">
              <div class="my-0 bd-highlight" style="height: 3vh; width: 100%">
                <div class="fw-bold fs-4 text-dark">
                  {{ this.$cookies.get("account").username }}
                </div>
              </div>
              <div class="bd-highlight">
                <div class="fs-5 text-dark" :class="center">
                  {{ this.$cookies.get("account").email }}
                </div>
              </div>
            </div>
          </div>
          <div class="bg-light my-3"></div>

          <!-- left side -->
          <div class="d-flex">
            <div class="flex-fill bg-white" style="height: 70vh; width: 90%">
              <div class="fw-bold fs-5 text-dark">
                <form name="signup">
                  <!-- 1 -->
                  <div class="row my-2">
                    <div class="form-group col-12">
                      <label class="form-label" for="username"
                        >Tracking Device</label
                      >

                      <!-- 2 -->
                      <div class="d-flex flex-row">
                        <input
                          class="form-control"
                          type="text"
                          id="username"
                          name="username"
                          required
                          placeholder="My tracking device’s name"
                          maxlength="20"
                          v-model="username"
                        />
                        <button
                          class="btn border-dark bg-dark py-0 text-white fw-bold fs-4 border-3"
                          style="height: 100%; width: 20%"
                        >
                          Connect
                        </button>
                      </div>
                    </div>
                  </div>
                  <!-- 3 -->
                  <div class="row my-2">
                    <div class="form-group col-12">
                      <label class="form-label" for="password"
                        >Connected Devices</label
                      >
                      <!-- 4 -->
                      <div class="d-flex flex-row">
                        <select
                          v-model="slavename">
                          <option disabled value="">Please select one</option>
                          <option><before>A</before></option>
                          <option>B</option>
                          <option>C</option>
                        </select>
                        <input
                          class="form-control"
                          :type="showpassword ? 'text' : 'password'"
                          id="password"
                          required
                          placeholder="My device's name"
                          maxlength="20"
                          v-model="password"
                        />
                        <button
                          class="btn border-dark bg-dark py-0 text-white fw-bold fs-4 border-3"
                          style="height: 100%; width: 20%"
                        >
                          Select
                        </button>
                      </div>
                    </div>
                  </div>
                </form>

                <!-- Add Devices -->
                <div class="mt-4 fw-bold fs-5 text-dark" :class="center">
                  <div
                    class="bg-white px-0 py-1 border border-secondary border-3"
                    style="width: 80%; height: auto; border-radius: 8px"
                  >
                    <div
                      class="mx-0 py-2 text-dark fw-bold fs-4"
                      :class="center"
                    >
                      Add Device
                    </div>
                    <div class="mx-5 text-dark fw-bold fs-4">
                      <form name="signup">
                        <!-- 1 -->
                        <div class="d-flex flex-row my-2">
                          <div class="flex-fill form-group">
                            <!-- 2 -->
                            <select
                              class="form-control"
                              type="text"
                              id="username"
                              name="username"
                              required
                              placeholder="My tracking device’s name"
                              maxlength="50"
                              v-model="username"
                            />
                          </div>
                          <button
                            class="btn border-dark bg-dark py-0 text-white fw-bold fs-4 border-3"
                            style="height: 100%; width: 25%"
                          >
                            Connect
                          </button>
                        </div>
                        <!-- 3 -->
                        <div class="d-flex flex-row my-2">
                          <div class="flex-fill form-group">
                            <!-- 4 -->
                            <input
                              class="form-control"
                              type="text"
                              id="password"
                              required
                              placeholder="Connect a new device"
                              maxlength="50"
                              v-model="password"
                            />
                          </div>
                          <button
                            class="btn border-dark bg-dark py-0 text-white fw-bold fs-4 border-3"
                            style="height: 100%; width: 25%"
                          >
                            Connect
                          </button>
                        </div>
                        <!-- 5 -->
                        <div class="mb-2 row my-2">
                          <div class="form-group">
                            <!-- 6 -->
                            <input
                              class="form-control"
                              :type="showpassword ? 'text' : 'password'"
                              id="password"
                              required
                              placeholder="Password"
                              maxlength="50"
                              v-model="password"
                            />
                          </div>
                        </div>
                        <div
                          class="mt-3 fw-bold fs-5 text-dark"
                          :class="center"
                        >
                          <button
                            class="mb-3 btn border-dark py-0 text-dark fw-bold fs-4 border-3"
                            style="height: auto; width: 50%"
                          >
                            CONFIRM
                          </button>
                        </div>
                      </form>
                    </div>
                  </div>
                  <!-- /Add Devices -->
                </div>
              </div>
              <div class="ms-3 mt-3" style="height: auto; width: auto">
                <div class="my-0 bd-highlight" style="height: 3vh; width: 100%">
                  <div class="fw-bold fs-4 text-dark">My Email Address</div>
                </div>
                <div class="bd-highlight mt-3">
                  <div class="fs-5 text-dark">
                    <img
                      :src="require('@/assets/image3.png')"
                      style="
                        max-height: 7.5vh;
                        max-width: 7.5vw;
                        border-radius: 80%;
                      "
                    />
                    {{ this.$cookies.get("account").email }}
                  </div>
                  <div
                    class="bg-highlight"
                    style="height: 1vh; width: 100%"
                  ></div>
                </div>
                <button
                  class="btn border-dark bg-dark py-0 text-white fw-bold fs-6 border-3"
                  style="height: 100%; width: 25%"
                >
                  Add Email Address
                </button>
              </div>
            </div>

            <!-- middle-blank -->
            <div class="flex-fill bg-white" style="height: 70vh; width: 5%">
              <div class="d-flex">
                <div class="flex-fill bg-highlight"></div>
              </div>
            </div>

            <!-- right side -->
            <div
              class="d-flex flex-column bd-highlight mb-3"
              style="width: 100%; height: 50%"
            >
              <div class="bg-highlight" style="height: auto; width: 100%"></div>
              <div
                class="d-flex flex-column bg-white px-0 py-1 border border-secondary border-3"
                :class="center"
                style="width: 100%; height: auto; border-radius: 8px"
              >
                <div class="bg-highlight" style="height: auto; width: 90%">
                  <div class="d-flex">
                    <div
                      class="flex-fill bg-highlight"
                      style="height: auto; width: 90%"
                    >
                      <div
                        class="mx-0 py-2 text-dark fw-bold fs-4"
                        :class="center"
                      >
                        Settings
                      </div>
                      <div class="fw-bold fs-5 text-dark">
                        <form name="signup">
                          <!-- 1 -->
                          <div class="row my-2">
                            <div class="form-group col-12">
                              <label class="form-label" for="username"
                                >Device</label
                              >

                              <!-- 2 -->
                              <div class="d-flex flex-row">
                                <input
                                  class="form-control"
                                  type="text"
                                  id="username"
                                  name="username"
                                  required
                                  placeholder="My device’s name"
                                  maxlength="20"
                                  v-model="username"
                                />
                                <button
                                  class="btn border-dark bg-dark py-0 text-white fw-bold fs-4 border-3"
                                  style="height: auto; width: 20%"
                                >
                                  Select
                                </button>
                              </div>
                            </div>
                          </div>
                          <!-- 3 -->
                          <div class="row my-2">
                            <div class="form-group col-12">
                              <label class="form-label" for="password"
                                >Tracking Distance</label
                              >
                              <!-- 4 -->
                              <div class="d-flex flex-row">
                                <input
                                  class="form-control"
                                  :type="showpassword ? 'text' : 'password'"
                                  id="password"
                                  required
                                  placeholder="Notify when out of range (meters)"
                                  maxlength="20"
                                  v-model="password"
                                />
                              </div>
                            </div>
                          </div>
                          <div class="row my-2">
                            <div class="form-group col-12">
                              <label class="form-label" for="username"
                                >Notification Message and Alert Sound</label
                              >

                              <!-- 2 -->
                              <div class="d-flex flex-row">
                                <input
                                  class="form-control"
                                  type="text"
                                  id="username"
                                  name="username"
                                  required
                                  placeholder="Notification & Alert format"
                                  maxlength="20"
                                  v-model="username"
                                />
                                <button
                                  class="btn border-dark bg-dark py-0 text-white fw-bold fs-4 border-3"
                                  style="height: auto; width: 20%"
                                >
                                  Select
                                </button>
                              </div>
                            </div>
                          </div>
                          <div
                            class="mt-3 fw-bold fs-5 text-dark"
                            :class="center"
                          >
                            <button
                              class="mb-3 btn border-dark py-0 text-dark fw-bold fs-4 border-3"
                              style="height: auto; width: 40%"
                            >
                              CONFIRM
                            </button>
                          </div>
                        </form>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>

        <!-- right-blank -->
        <div class="flex-fill"></div>
      </div>
    </div>
  </div>
</template>

<script>
// @ is an alias to /src
export default {
  name: "ProfilePage",
  data() {
    return {
      previousRoutes: [],
      search: "",
      center: {
        "d-flex": true,
        "justify-content-center": true,
        "align-items-center": true,
      },
    };
  },
  mounted() {},
  methods: {},
  watch: {
    $route(to, from) {
      this.previousRoutes.push(from); // เมื่อมีการเปลี่ยนเส้นทางใหม่ ให้เก็บเส้นทางก่อนหน้าลงในอาร์เรย์
    },
  },
};
</script>
