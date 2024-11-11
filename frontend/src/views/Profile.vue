<template>
  <div id="app">
    <div class="bg-highlight" style="height: 3vh; width: 100%"></div>
    <div style="height: auto">
      <div class="d-flex">
        <!-- left-blank -->
        <div class="flex-fill"></div>

        <div class="flex-fill" style="height: 150vh; width: 90%">
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
              <div class="my-0 bd-highlight" style="height: 3vh;">
                <div class="fw-bold fs-4 text-dark">
                  {{ this.$cookies.get("account").username }}
                </div>
              </div>
              <div class="px-0 py-0 ms-auto mt-1 bd-highlight">
                <div class="ms-auto mx-0 fs-5 text-dark">
                  {{ this.$cookies.get("account").email }}
                </div>
              </div>
            </div>
          </div>
          <div class="bg-light my-3"></div>

          <!-- left side -->
          <div class="d-flex">
            <div class="flex-fill bg-white" style="height: auto; width: 90%">
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
                          style="height: 100%; width: auto"
                        >
                          Connect
                        </button>
                      </div>
                    </div>
                  </div>
                  <!-- 3 -->
                  <div class="row my-2">
                    <div class="form-group col-12">
                      <label class="form-label">Connected Devices</label>
                      <!-- 4 -->
                      <div class="d-flex flex-row">
                        <select
                                  request
                                  class="btn border-dark bg-secondary py-0 text-white fw-bold fs-4 border-3"
                                  style="height: 100%; width: 100%"
                                  v-model="slavename2"
                                >
                                  <option disabled selected value>
                                    Select Device
                                  </option>
                                  <option
                                    v-for="slave in users"
                                    :key="slave.slavename2"
                                  >
                                    <before>{{ slave.slavename }}</before>
                                  </option>
                                </select>
                      </div>
                    </div>
                  </div>
                </form>

                <!-- Add Devices -->
                <div class="mt-4 fw-bold fs-5 text-dark" :class="center">
                  <div
                    class="bg-white px-0 py-1 border border-secondary border-3"
                    style="width: 80%; height: auto; border-radius: 25px"
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
                            <div class="d-flex flex-column">
                              <input
                                class="form-control"
                                type="text"
                                id="mastername"
                                name="mastername"
                                required
                                placeholder="My tracking device’s name"
                                maxlength="10"
                                v-model="mastername"
                              />
                            </div>
                            <template v-if="$v.mastername.$error">
                              <p
                                class="text-danger m-0 fs-5 p-0"
                                v-if="!$v.mastername.required"
                              >
                                Required This
                              </p>
                            </template>
                          </div>
                          <button
                            class="btn border-dark bg-dark py-0 text-white fw-bold fs-4 border-3"
                            style="height: 100%; width: auto"
                          >
                            Connect
                          </button>
                        </div>
                        <!-- 3 -->
                        <div class="d-flex flex-row my-2">
                          <div class="flex-fill form-group">
                            <div class="d-flex flex-column">
                              <!-- 4 -->
                              <input
                                class="form-control"
                                type="text"
                                id="devicename"
                                name="devicename"
                                required
                                placeholder="Connect a new device"
                                maxlength="10"
                                v-model="slavename1"
                              />
                            </div>
                            <template v-if="$v.slavename1.$error">
                              <p
                                class="text-danger m-0 fs-5 p-0"
                                v-if="!$v.slavename1.required"
                              >
                                Required This
                              </p>
                            </template>
                          </div>
                          <button
                            class="btn border-dark bg-dark py-0 text-white fw-bold fs-4 border-3"
                            style="height: 100%; width: auto"
                          >
                            Connect
                          </button>
                        </div>
                        <!-- 5 -->
                        <div class="d-flex flex-row my-2">
                          <div class="flex-fill form-group">
                            <div class="d-flex flex-column">
                              <!-- 6 -->
                              <input
                                class="form-control"
                                :type="showpassword ? 'text' : 'password'"
                                id="password"
                                required
                                placeholder="Password"
                                maxlength="20"
                                v-model="password"
                              />
                            </div>
                            <template v-if="$v.password.$error">
                              <p
                                class="text-danger m-0 fs-5 p-0"
                                v-if="!$v.password.required"
                              >
                                Required This
                              </p>
                            </template>
                          </div>
                          <input
                            class="form-check-input my-0 nx-0"
                            type="checkbox"
                            style="height: 37px; width: 37px"
                            id="check"
                            v-model="showpassword"
                          />
                        </div>
                        <div
                          class="mt-3 fw-bold fs-5 text-dark"
                          :class="center"
                        >
                          <button
                            class="mb-3 btn border-dark py-0 text-dark fw-bold fs-4 border-3"
                            style="height: auto; width: 50%"
                            @click="Adding()"
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
                  <div class="fs-5 fw-bold text-dark">
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
                    class="bg-highlight "
                    style="height: 1vh; width: 100%"
                  ></div>
                
                <button
                  class="btn border-dark bg-dark py-0 text-white fw-bold fs-6 border-5"
                  style="height: auto; width: auto"
                >
                  Add Email Address
                </button>
              </div>

              </div>
            </div>

            <!-- middle-blank -->
            <div class="flex-fill bg-white" style="height: 80vh; width: 10%">
              <div class="d-flex">
                <div class="flex-fill bg-highlight"></div>
              </div>
            </div>

            <!-- right side -->
            <div
              class="d-flex flex-column bd-highlight mb-3 mt-5"
              style="width: 100%; height: 50%"
            >
              <div class="bg-highlight" style="height: auto; width: 100%"></div>
              <div
                class="d-flex flex-column bg-white px-0 py-1 border border-secondary border-3"
                :class="center"
                style="width: 100%; height: auto; border-radius: 25px"
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
                              <div class="d-flex flex-column">
                                <select
                                  request
                                  class="btn border-dark bg-secondary py-0 text-white fw-bold fs-4 border-3"
                                  style="height: 100%; width: 100%"
                                  v-model="slavename2"
                                >
                                  <option disabled selected value>
                                    Select Device
                                  </option>
                                  <option
                                    v-for="slave in users"
                                    :key="slave.slavename2"
                                  >
                                    <before>{{ slave.slavename }}</before>
                                  </option>
                                </select>
                                <template v-if="$v.slavename2.$error">
                                  <p
                                    class="text-danger m-0 p-0"
                                    v-if="!$v.slavename2.required"
                                  >
                                    Required This
                                  </p>
                                </template>
                              </div>
                            </div>
                          </div>
                          <!-- 3 -->
                          <div class="row my-2">
                            <div class="form-group col-12">
                              <label class="form-label" for="password" request
                                >Tracking Distance</label
                              >
                              <!-- 4 -->
                              <div class="d-flex flex-column">
                                <input
                                  class="form-control"
                                  type="number"
                                  id="threshold"
                                  required
                                  placeholder="Notify when out of range (meters)"
                                  maxlength="20"
                                  v-model="threshold"
                                />
                                <template v-if="$v.threshold.$error">
                                  <p
                                    class="text-danger m-0 p-0"
                                    v-if="!$v.threshold.required"
                                  >
                                    Required This
                                  </p>
                                </template>
                              </div>
                            </div>
                          </div>
                          <div class="row my-2">
                            <div class="form-group col-12">
                              <label class="form-label" for="username"
                                >Notification Message and Alert Sound</label
                              >
                              <form confirm="return checkForm();">
                                <!-- 2 -->
                                <div class="d-flex flex-column">
                                  <select
                                    id="notification"
                                    class="btn border-dark bg-secondary py-0 text-white fw-bold fs-4 border-3"
                                    :class="{
                                      'border-danger': $v.notify.$error,
                                    }"
                                    style="height: 100%; width: 100%"
                                    v-model="notify"
                                  >
                                    <option disabled selected value>
                                      Select Option
                                    </option>
                                    <option
                                      value="Notification Message and Alert Sound"
                                    >
                                      Turn on Notification Message and Alert
                                      Sound
                                    </option>
                                    <option value="Notification Message">
                                      Turn on Notification Message
                                    </option>
                                    <option value="Alert Sound">
                                      Turn on Alert Sound
                                    </option>
                                    <option
                                      value="Turn off Notification and Alert"
                                    >
                                      Turn off
                                    </option>
                                  </select>
                                  <template v-if="$v.notify.$error">
                                    <p
                                      class="text-danger m-0 p-0"
                                      v-if="!$v.notify.required"
                                    >
                                      Required This
                                    </p>
                                  </template>
                                </div>
                              </form>
                            </div>
                          </div>
                          <div
                            class="mt-3 fw-bold fs-5 text-dark"
                            :class="center"
                          >
                            <button
                              class="mb-3 btn border-dark py-0 text-dark fw-bold fs-4 border-3"
                              style="height: auto; width: 35.56%"
                              @click="Setting()"
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
import axios from "axios";
import {
  required,
  maxLength,
} from "vuelidate/lib/validators";

export default {
  name: "ProfilePage",
  data() {
    return {
      previousRoutes: [],
      users: [],
      password: "",
      showpassword: false,
      slaves: [],
      slavename1: "",
      slavename2: "",
      slavename: "",
      threshold: "",
      mastername: "",
      master: "",
      notify: "",
      search: "",
      center: {
        "d-flex": true,
        "justify-content-center": true,
        "align-items-center": true,
      },
    };
  },
  validations: {
    mastername: {
      required: required,
      maxLength: maxLength(10),
    },
    slavename1: {
      required: required,
      maxLength: maxLength(10),
    },
    slavename2: {
      required: required,
    },
    threshold: {
      required: required,
    },
    notify: {
      required: required,
    },
    password: {
      required: required,
    },
  },
  mounted() {
    this.getSlave();
  },
  methods: {
    getSlave() {
      axios
        .get("http://localhost:3000/userSlave", {
          params: {
            search: this.$cookies.get("account").username,
          },
        })
        .then((response) => {
          this.users = response.data;
        })
        .catch((err) => {
          console.log(err);
        });
    },

    
    Adding() {
      this.$v.mastername.$touch();
      this.$v.slavename1.$touch();
      this.$v.password.$touch();
      if (
        !this.$v.mastername.$invalid &&
        !this.$v.slavename1.$invalid &&
        !this.$v.password.$invalid
      ) {
        const data = {
          mastername: this.mastername,
          slavename: this.slavename1,
          username: this.$cookies.get("account").username,
          password: this.password,
        };
        axios
          .post("http://localhost:3000/slaveAdding", data)
          .then(() => {
            alert("Success");
          })
          .catch((err) => {
            alert(err.response.data.details.message);
          });
      }
    },

    Setting() {
      this.$v.slavename2.$touch();
      this.$v.threshold.$touch();
      this.$v.notify.$touch();
      if (
        !this.$v.slavename2.$invalid &&
        !this.$v.threshold.$invalid &&
        !this.$v.notify.$invalid
      ) {
        const data = {
          slavename: this.slavename2,
          threshold: this.threshold,
          notify: this.notify,
        };
        axios
          .post("http://localhost:3000/slaveSetting", data)
          .then(() => {
            //this.$router.push({ path: "/profile" });
            alert("Success");
          })
          .catch((err) => {
            alert(err.response.data.details.message);
          });
      }
    },
  },
  watch: {
    $route(to, from) {
      this.previousRoutes.push(from); // เมื่อมีการเปลี่ยนเส้นทางใหม่ ให้เก็บเส้นทางก่อนหน้าลงในอาร์เรย์
    },
  },
};
</script>